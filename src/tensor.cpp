//
// Created by vlado on 2/2/20.
//

#include "../include/tensor.h"
#include "../include/assertions.h"
#include "../include/functional.h"

#include <utility>

//#define __assert_tensor_dimensions_init \
//    assert(mul(this->dimensions) == this->elements.size(), \
//    "Tensor dimensions expect "_pr + mul(this->dimensions) + " elements, but " + this->elements.size() +\
//    " received.")

#define __assert_tensor_dimensions_equal(a, b) \
    assert(a.dimensions == b.dimensions, "Tensors should have same dimensions. Found " + a.dimensions + " and " + b.dimensions + ".")

// constructors
tensor::tensor() : rank{0}, dimensions{0}, elements{0} {}
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

tensor::tensor(dim dimensions, num element) : rank{dimensions.size()}, dimensions{std::move(dimensions)},
                                              elements(mul(this->dimensions), element) {}

vector<tensor> tensor::subdim() const {
    vector<tensor> results(dimensions[0], tensor({dimensions.begin() + 1, dimensions.end()}, 0));
    const auto elements_count = elements.size() / dimensions[0]; // elements in each sub-dimension

    for (auto i = 0u; i < dimensions[0]; ++i) {
        auto &el = results[i].elements = vec(elements_count);

        for (auto j = 0u; j < elements_count; ++j) {
            el[j] = elements[i * elements_count + j];
        }
    }

    return results;
}

num tensor::element(cdim index) const {
    return elements[index * dimensions];
}

tensor operator+(ctensor a, ctensor b) {
    __assert_tensor_dimensions_equal(a, b)

    tensor result(a);
    return a;
}
