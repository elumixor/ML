//
// Created by vlado on 2/2/20.
//

#include "../include/tensor.h"
#include "../include/assertions.h"
#include "../include/functional.h"

#include <utility>

#define __assert_tensor_dimensions \
    assert(mul(this->dimensions) == this->elements.size(), \
    "Tensor dimensions expect "_pr + mul(this->dimensions) + " elements, but " + this->elements.size() +\
    " received.")

// constructors
tensor::tensor(vec elements) : rank{1}, dimensions{1}, elements{std::move(elements)} {}
tensor::tensor(vec elements, dim dimensions) : rank{dimensions.size()}, dimensions{std::move(dimensions)},
                                               elements{std::move(elements)} {
    __assert_tensor_dimensions
}
tensor::tensor() : rank{0}, dimensions{0}, elements{0} {}
tensor::tensor(num element, dim dimensions) : rank{dimensions.size()}, dimensions{std::move(dimensions)},
                                              elements(mul(this->dimensions), element) {}
