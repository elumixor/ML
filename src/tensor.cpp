//
// Created by vlado on 2/2/20.
//

#include "tensor.h"
#include "assertions.h"
#include "functional.h"
#include "iterable.h"

#include <utility>

//#define __assert_tensor_dimensions_init \
//    assert(mul(this->dimensions) == this->elements.size(), \
//    "Tensor dimensions expect "_pr + mul(this->dimensions) + " elements, but " + this->elements.size() +\
//    " received.")

#define __assert_tensor_dimensions_equal(a, b) \
    assert(a.dimensions == b.dimensions, "Tensors should have same dimensions. Found " + a.dimensions + " and " + b.dimensions + ".")

// constructors
tensor::tensor(std::initializer_list<num> elements) : rank{1}, dimensions{elements.size()}, elements{elements} {}
tensor::tensor(std::initializer_list<tensor> elements) : rank{elements.begin()->rank + 1}, dimensions(rank) {
    const auto &b = *elements.begin();
    uint size{0u};

    dimensions[0] = elements.size();

    for (auto j = 1u; j < rank; ++j)
        dimensions[j] = b.dimensions[j - 1];

    for (const auto &item : elements)
        size += item.elements.size();

    this->elements.reserve(size);

    for (const auto &element : elements)
        this->elements.insert(this->elements.end(), element.elements.begin(), element.elements.end());
}
tensor::tensor(vec elements, vnat dimensions) : rank{dimensions.size()}, dimensions{std::move(dimensions)}, elements{std::move(elements)} {}
tensor::tensor(num element, cvnat dimensions) : rank{dimensions.size()}, dimensions{dimensions}, elements(mul(dimensions), element) {}

vector<tensor> tensor::subdim() const {
    vector<tensor> results(dimensions[0], tensor(0, {dimensions.begin() + 1, dimensions.end()}));
    val elements_count = elements.size() / dimensions[0]; // elements in each sub-dimension

    for (var i = 0u; i < dimensions[0]; ++i) {
        var &el = results[i].elements = vec(elements_count);

        for (var j{0u}; j < elements_count; ++j)
            el[j] = elements[i * elements_count + j];
    }

    return results;
}
num tensor::element(cvnat index) const {
    return elements[index * dimensions];
}
tensor tensor::reshaped(cvnat new_dim) const {
    return tensor(elements, new_dim);
}
tensor &tensor::reshape(cvnat new_dim) {
    this->dimensions = new_dim;
    return *this;
}
tensor::operator num() const {
    assert(rank == 0, "Only rank 0 tensor can be converted into a scalar number. Found rank " + rank + " tensor");

    return elements[0];
}
tensor tensor::operator[](uint dim) const {
    assert(rank > 0, "Rank 0 tensor has no sub-dimensions.")
    assert(dim < dimensions[0], "Tried to get " + dim + " component in first dimension, while it contains " + dimensions[0] + ".")

    return subdim()[dim];
}
tensor tensor::subdim(uint dimension, uint offset, bool flatten) const {
    val dim_size{dimension == 0 ? 1 : dimensions[dimension - 1]};
    val size = elements.size();
    vec els(size / dimensions[dimension]);

    val elements_in_dim{dimension + 1 == rank ? 0 : mul(slice(dimensions, dimension + 1))};
    var k{dimension + 1 == rank ? offset : elements_in_dim * offset};

    var j{0u};
    for (var d{0u}; d < dim_size; d++) {
        for (var i{0u}; i < elements_in_dim; i++)
            els[j++] = elements[k++];

        k += elements_in_dim;
    }

    if (!flatten) {
        vnat new_dims(dimensions);
        new_dims[dimension] = 1;
        return tensor(els, new_dims);
    }

    vnat new_dims{splice(dimensions, dimension)};
    return tensor(els, new_dims);
}

tensor operator+(ctensor a, ctensor b) {
    __assert_tensor_dimensions_equal(a, b)

    tensor result(a);
    return a;
}
