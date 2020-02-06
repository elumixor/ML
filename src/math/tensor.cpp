//
// Created by vlado on 2/2/20.
//

#include "math/tensor.h"
#include "assertions.h"
#include "math/matht.h"
#include "iterable.h"

#include <utility>
#include <math/random.h>
#include <functional>

// constructors
tensor::tensor() = default;
tensor::tensor(params<num> numbers) : rank{1}, dimensions{numbers.size()}, elements{numbers} {}
tensor::tensor(params<tensor> tensors) : rank{tensors.begin()->rank + 1}, dimensions(rank), elements{} {
    const auto &b = *tensors.begin();
    nat size{0u};

    dimensions[0] = tensors.size();

    for (auto j = 1u; j < rank; ++j)
        dimensions[j] = b.dimensions[j - 1];

    for (const auto &item : tensors)
        size += item.size();

    this->elements.reserve(size);

    for (cval element : tensors)
        this->elements.insert(this->elements.end(), element.elements.begin(), element.elements.end());
}
tensor::tensor(vnat dimensions, vec elements) : rank{dimensions.size()}, move_init_s(dimensions), move_init_s(elements) {}
tensor::tensor(vnat dimensions, num element) : rank{dimensions.size()}, move_init_s(dimensions),
                                               elements(product(this->dimensions), element) {}
tensor::tensor(vec elements) : rank{0}, dimensions{elements.size()}, move_init_s(elements) {}

// Copy and move
tensor::tensor(const tensor &other) = default;
tensor::tensor(tensor &&other) noexcept : rank{other.rank}, move_init(dimensions, other), move_init(elements, other) {}
tensor &tensor::operator=(ctensor other) {
    if (this == &other) return *this;

    rank = other.rank;
    dimensions = vnat(other.rank);
    elements = vec(other.elements);

    return *this;
}
tensor &tensor::operator=(tensor &&other) noexcept {
    if (this == &other) return *this;

    rank = other.rank;
    dimensions = std::move(other.dimensions);
    elements = std::move(other.elements);

    return *this;
}

// Static tensor
tensor tensor::random(cvnat dimensions, num min, num max) {
    return tensor(dimensions, vec_uniform(product(dimensions), min, max));
}
tensor tensor::random_normal(const vnat &dimensions, num mean, num std) {
    return tensor(dimensions, vec_normal(product(dimensions), mean, std));
}

tensor tensor::reshaped(cvnat new_dim) const {
    return tensor(new_dim, elements);
}
tensor &tensor::reshape(cvnat new_dim) {
    this->dimensions = new_dim;
    return *this;
}
num tensor::element(cvnat index) const {
    return elements[index * dimensions];
}
array<tensor> tensor::subdim() const {
    array<tensor> results(dimensions[0], tensor({dimensions.begin() + 1, dimensions.end()}, 0));
    val elements_count = size() / dimensions[0]; // elements in each sub-dimension

    for (var i = 0u; i < dimensions[0]; ++i) {
        var &el = results[i].elements = vec(elements_count);

        for (var j{0u}; j < elements_count; ++j)
            el[j] = elements[i * elements_count + j];
    }

    return results;
}
tensor tensor::operator[](nat component) const {
    require(rank > 0, "Rank 0 tensor has no sub-dimensions.")
    require(component < dimensions[0],
            "Tried to get " + component + " component in first dimension, while it contains " + dimensions[0] + ".")

    return subdim()[component];
}
vec tensor::vector(nat fixed_dim, cvnat indices) const {
    var offset{0u};
    var dim_size{1u};

    const int fd = fixed_dim;
    for (var k{to_int(rank - 1)}; k > fd; --k) {
        offset += indices[k - 1] * dim_size;
        dim_size *= dimensions[k];
    }

    dim_size *= dimensions[fixed_dim];

    for (var k{fd - 1}; k >= 0; --k) {
        offset += indices[k] * dim_size;
        dim_size *= dimensions[k];
    }

    val step{product(slice(dimensions, to_nat(fixed_dim + 1), -1))};
    vec result;
    val elements_count{dimensions[fixed_dim]};
    result.reserve(elements_count);

    for (var j{0u}; j < elements_count; ++j) {
        result.push_back(elements[offset]);
        offset += step;
    }

    return result;
}

tensor tensor::subdim(nat dimension, nat offset, bool flatten) const {
    check(dimension < rank, "Cannot subdim at dimension " + dimension + " of T" + rank + ".");

    val component{dimensions[dimension]};
    check(offset < component, "Offset " + offset + " is out of bounds. " + component + " components in dimension in total.");

    val parent_component{product(splice(dimensions, dimension, -1))};
    val subdim_elements{size() / (parent_component * component)};
    val stride{subdim_elements * (component - 1)};
    vec els(subdim_elements * parent_component);

    var k{offset * (subdim_elements)};

    var j{0u};
    for (var i{0u}; i < parent_component; ++i) {
        for (var l{0u}; l < subdim_elements; ++l) {
            els[j++] = elements[k++];
        }
        k += stride;
    }

    if (!flatten) {
        vnat new_dims(dimensions);
        new_dims[dimension] = 1;
        return tensor(new_dims, els);
    }

    vnat new_dims{splice(dimensions, dimension)};
    return tensor(new_dims, els);
}
tensor::operator num() const {
    require(rank == 0, "Only rank 0 tensor can be converted into a scalar number. Found rank " + rank + " tensor");

    return elements[0];
}

tensor operator+(ctensor a, ctensor b) {
    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")

    val size = a.size();
    vec els(size);
    for (var i{0u}; i < size; ++i)
        els[i] = a.elements[i] + b.elements[i];

    return tensor(a.dimensions, els);
}
tensor operator-(ctensor a, ctensor b) { return a + -1 * b; }
tensor operator+(ctensor a, num b) { return a + tensor(a.dimensions, b); }
tensor operator-(ctensor a, num b) {
    return a + -b;
}
tensor operator*(ctensor a, ctensor b) {
    if (b.rank == 0) return a * to_num(b);
    else if (a.rank == 0) return to_num(a) * b;

    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")

    val size = a.size();
    vec els(size);
    for (var i{0u}; i < a.size(); ++i)
        els[i] = a.elements[i] * b.elements[i];

    return tensor(a.dimensions, els);
}
tensor operator*(ctensor a, num b) {
    val size = a.size();
    vec els(size);
    for (var i{0u}; i < a.size(); ++i)
        els[i] = a.elements[i] * b;

    return tensor(a.dimensions, els);
}
tensor operator*(num b, ctensor a) {
    val size = a.size();
    vec els(size);
    for (var i{0u}; i < a.size(); ++i)
        els[i] = a.elements[i] * b;

    return tensor(a.dimensions, els);
}
tensor operator/(ctensor a, num b) { return a * (to_num(1) / b); }
tensor &operator+=(tensor &a, const tensor &b) {
    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")

    val size = a.size();
    for (var i{0u}; i < size; ++i)
        a.elements[i] += b.elements[i];

    return a;
}
