//
// Created by vlado on 2/2/20.
//

#include <math/tensor.h>
#include <math/matht.h>

/* Helper functions */
/** Transforms composite index in multiple dimensions to a single index in one dimension for elements array */
nat get_single_index(dim cref index, dim cref dimensions) {
    nat s{0};
    nat dim_size{1};
    nat i{dimensions.size};
    do {
        i--;
        s += index[i] * dim_size;
        dim_size *= dimensions[i];
    } while (i > 0);

    return s;
}

///* Constructors */
//tensor::tensor(params<scalar> numbers) : rank{1}, dimensions{numbers.size()}, elements{numbers} {}
//tensor::tensor(params<tensor> tensors) : rank{tensors.begin()->rank + 1}, dimensions(rank), elements{} {
//    const auto &b = *tensors.begin();
//    nat size{0u};
//
//    dimensions[0] = tensors.size();
//
//    for (auto j = 1u; j < rank; ++j)
//        dimensions[j] = b.dimensions[j - 1];
//
//    for (const auto &item : tensors)
//        size += item.size();
//
//    this->elements.reserve(size);
//
//    for (cval element : tensors)
//        this->elements.insert(this->elements.end(), element.elements.begin(), element.elements.end());
//}
//tensor::tensor(vnat dimensions, vec elements) : rank{dimensions.size()}, move_init_s(dimensions), move_init_s(elements) {}
//tensor::tensor(vnat dimensions, scalar element) : rank{dimensions.size()}, move_init_s(dimensions),
//                                                  elements(product(this->dimensions), element) {}
//tensor::tensor(vec elements) : rank{0}, dimensions{elements.size()}, move_init_s(elements) {}
//
//// Copy and move
//tensor::tensor(const tensor &other) = default;
//tensor::tensor(tensor &&other) noexcept : rank{other.rank}, move_init(dimensions, other), move_init(elements, other) {}
//tensor &tensor::operator=(ctensor other) {
//    if (this == &other) return *this;
//
//    rank = other.rank;
//    dimensions = vnat(other.rank);
//    elements = vec(other.elements);
//
//    return *this;
//}
//tensor &tensor::operator=(tensor &&other) noexcept {
//    if (this == &other) return *this;
//
//    rank = other.rank;
//    dimensions = std::move(other.dimensions);
//    elements = std::move(other.elements);
//
//    return *this;
//}
//
///* Static tensor */
//tensor tensor::random(cvnat dimensions, scalar min, scalar max) {
//    return tensor(dimensions, random_uniform(product(dimensions), min, max));
//}
//tensor tensor::random_normal(cvnat dimensions, scalar mean, scalar std) {
//    return tensor(dimensions, ::random_normal(product(dimensions), mean, std));
//}
//tensor tensor::reshaped(cvnat new_dim) const {
//    return tensor(new_dim, elements);
//}
//tensor &tensor::reshape(cvnat new_dim) {
//    this->dimensions = new_dim;
//    return *this;
//}
//array<tensor> tensor::subdim() const {
//    array<tensor> results(dimensions[0], tensor({dimensions.begin() + 1, dimensions.end()}, 0));
//    val elements_count = size() / dimensions[0]; // elements in each sub-dimension
//
//    for (var i = 0u; i < dimensions[0]; ++i) {
//        var &el = results[i].elements = vec(elements_count);
//
//        for (var j{0u}; j < elements_count; ++j)
//            el[j] = elements[i * elements_count + j];
//    }
//
//    return results;
//}
//vec tensor::vector(nat fixed_dim, cvnat indices) const {
//    if (rank < 2) return elements;
//
//    var offset{0u};
//    var dim_size{1u};
//    cval ds = dimensions[fixed_dim];
//    val fd = to_int(fixed_dim);
//
//    for (var k{to_int(rank - 1)}; k > fd; --k) {
//        offset += indices[k - 1] * dim_size;
//        dim_size *= dimensions[k];
//    }
//
//    dim_size *= ds;
//
//    for (var k{fd - 1}; k >= 0; --k) {
//        offset += indices[k] * dim_size;
//        dim_size *= dimensions[k];
//    }
//
//    val step{product(slice(dimensions, to_nat(fixed_dim + 1), -1))};
//    vec result;
//    val elements_count{ds};
//    result.reserve(elements_count);
//
//    for (var j{0u}; j < elements_count; ++j) {
//        result.push_back(elements[offset]);
//        offset += step;
//    }
//
//    return result;
//}
//
///* Sub-dimensions, vectors and elements selection */
//tensor tensor::subdim(nat dimension, nat offset, bool flatten) const {
//    check(dimension < rank, "Cannot subdim at dimension " + dimension + " of T" + rank + ".");
//
//    val component{dimensions[dimension]};
//    check(offset < component, "Offset " + offset + " is out of bounds. " + component + " components in dimension in total.");
//
//    val parent_component{product(splice(dimensions, dimension, -1))};
//    val subdim_elements{size() / (parent_component * component)};
//    val stride{subdim_elements * (component - 1)};
//    vec els(subdim_elements * parent_component);
//
//    var k{offset * (subdim_elements)};
//
//    var j{0u};
//    for (var i{0u}; i < parent_component; ++i) {
//        for (var l{0u}; l < subdim_elements; ++l) {
//            els[j++] = elements[k++];
//        }
//        k += stride;
//    }
//
//    if (!flatten) {
//        vnat new_dims(dimensions);
//        new_dims[dimension] = 1;
//        return tensor(new_dims, els);
//    }
//
//    vnat new_dims{splice(dimensions, dimension)};
//    return tensor(new_dims, els);
//}
//tensor::operator scalar() const {
//    require(rank == 0, "Only rank 0 tensor can be converted into a scalar number. Found rank " + rank + " tensor");
//
//    return elements[0];
//}
//scalar &tensor::operator[](cvnat index) { return elements[get_single_index(index, dimensions)]; }
//
///* Arithmetics operators */
//// Unary minus
//tensor operator-(const tensor &a) {
//    val size{a.size()};
//    vec elements;
//    elements.reserve(size);
//    for (var i{0u}; i < size; ++i)
//        elements.push_back(a.elements[i] * -1);
//    return tensor(elements);
//}
//// Addition and subtractions (element-wise)
//tensor operator+(ctensor a, ctensor b) {
//    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")
//
//    val size = a.size();
//    vec els(size);
//    for (var i{0u}; i < size; ++i)
//        els[i] = a.elements[i] + b.elements[i];
//
//    return tensor(a.dimensions, els);
//}
//tensor operator-(ctensor a, ctensor b) { return a + -1 * b; }
//// Extending scalar to a tensor
//tensor operator+(ctensor a, scalar b) { return a + tensor(a.dimensions, b); }
//tensor operator-(ctensor a, scalar b) {
//    return a + -b;
//}
//// Scalar multiplication
//tensor operator*(ctensor a, scalar b) {
//    val size = a.size();
//    vec els(size);
//    for (var i{0u}; i < a.size(); ++i)
//        els[i] = a.elements[i] * b;
//
//    return tensor(a.dimensions, els);
//}
//tensor operator*(ctensor a, ctensor b) {
//    if (b.rank == 0) return a * to_scalar(b);
//    else if (a.rank == 0) return to_scalar(a) * b;
//
//    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")
//
//    val size = a.size();
//    vec els;
//    els.reserve(size);
//    for (var i{0u}; i < size; ++i)
//        els.push_back(a.elements[i] * b.elements[i]);
//
//    return tensor(a.dimensions, els);
//}
//tensor operator*(scalar b, ctensor a) {
//    val size = a.size();
//    vec els(size);
//    for (var i{0u}; i < a.size(); ++i)
//        els[i] = a.elements[i] * b;
//
//    return tensor(a.dimensions, els);
//}
//tensor operator/(ctensor a, scalar b) { return a * (to_scalar(1) / b); }
//// In-place operations
//tensor &operator+=(tensor &a, ctensor b) {
//    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")
//
//    val size = a.size();
//    for (var i{0u}; i < size; ++i)
//        a.elements[i] += b.elements[i];
//
//    return a;
//}
//tensor &operator-=(tensor &a, ctensor b) { return a += -b; }
//tensor &operator*=(tensor &a, scalar b) {
//    val size = a.size();
//    for (var i{0u}; i < size; ++i)
//        a.elements[i] *= b;
//
//    return a;
//}
//// Hadamard in-plcace
//tensor &operator*=(tensor &a, ctensor b) {
//    if (b.rank == 0) return a *= to_scalar(b);
//    else if (a.rank == 0) return a = to_scalar(a) * b;
//
//    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")
//
//    val size = a.size();
//    for (var i{0u}; i < size; ++i)
//        a.elements[i] *= b.elements[i];
//
//    return a;
//}
//tensor &operator/=(tensor &a, cnum b) { return a *= (to_scalar(1) / b); }

scalar ref tensor::operator[](dim cref indices) const {
    return operator[](get_single_index(indices, dimensions));
}

tensor::tensor(vec elements) : move_init_s(elements), dimensions{elements.size} {}
tensor::tensor(vec elements, dim dimensions) : move_init_s(elements), move_init_s(dimensions) {}
tensor::tensor(params<tensor> tensors) {
    // Init dimensions
    cval b = *tensors.begin();
    int rank{to_int(b.dimensions.size) + 1};

    dimensions.elements = new nat[rank];
    nat elements_count{dimensions.elements[0] = tensors.size()};

    for (var j{1}; j < rank; ++j)
        elements_count *= (dimensions.elements[j] = b.dimensions.elements[j - 1]);

    // Init elements
    elements.elements = new scalar[elements_count];
    var j{0u};
    for (cval tensor : tensors) {
        val size{tensor.elements.size};
        forsize elements.elements[j++] = tensor[i];
    }
}
tensor::tensor(params<vec> vectors) {
    // Init dimensions
    cval b = *vectors.begin();

    dimensions.elements = new nat[2];
    nat elements_count{dimensions.elements[0] = vectors.size()};
    elements_count *= (dimensions.elements[1] = b.size);

    // Init elements
    elements.elements = new scalar[elements_count];

    var j{0u};
    for (cval vector : vectors) {
        val size{vector.size};
        forsize elements.elements[j++] = vector[i];
    }
}
tensor tensor::of(scalar value, dim cref dimensions) { return tensor(vec::of(product(dimensions), value)); }
