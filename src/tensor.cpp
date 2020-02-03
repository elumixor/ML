//
// Created by vlado on 2/2/20.
//

#include "tensor.h"
#include "assertions.h"
#include "functional.h"
#include "iterable.h"

#include <utility>
#include <random.h>

// constructors
tensor::tensor(std::initializer_list<num> numbers) : rank{1}, dimensions{numbers.size()}, elements{numbers} {}
tensor::tensor(std::initializer_list<tensor> tensors) : rank{tensors.begin()->rank + 1}, dimensions(rank) {
    const auto &b = *tensors.begin();
    uint size{0u};

    dimensions[0] = tensors.size();

    for (auto j = 1u; j < rank; ++j)
        dimensions[j] = b.dimensions[j - 1];

    for (const auto &item : tensors)
        size += item.size();

    this->elements.reserve(size);

    for (const auto &element : tensors)
        this->elements.insert(this->elements.end(), element.elements.begin(), element.elements.end());
}
tensor::tensor(vnat dims, vec numbers) : rank{dims.size()}, dimensions{std::move(dims)}, elements{std::move(numbers)} {}
tensor::tensor(vnat dims, num number) : rank{dims.size()}, dimensions{std::move(dims)}, elements(product(this->dimensions), number) {}
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
tensor::operator num() const {
    assert(rank == 0, "Only rank 0 tensor can be converted into a scalar number. Found rank " + rank + " tensor");

    return elements[0];
}
tensor tensor::operator[](uint component) const {
    assert(rank > 0, "Rank 0 tensor has no sub-dimensions.")
    assert(component < dimensions[0],
           "Tried to get " + component + " component in first dimension, while it contains " + dimensions[0] + ".")

    return subdim()[component];
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
tensor tensor::subdim(uint dimension, uint offset, bool flatten) const {
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
num tensor::element(cvnat index) const {
    return elements[index * dimensions];
}

tensor operator+(ctensor a, ctensor b) {
    check(a.dimensions == b.dimensions, "Tensors should have same dimensions. Received " + a.dimensions + " and " + b.dimensions + ".")

    tensor result(a);
    return a;
}
num sum(const tensor &t) { return sum(t.elements); }
num mean(const tensor &t) { return sum(t) / t.size(); }

