//
// Created by vlado on 2/2/20.
//

#include "../include/tensor.h"

#include <utility>

tensor::tensor(vec data) : data{std::move(data)}, rank{1}, dimensions{1} {}
tensor::tensor() : data{0}, rank{0}, dimensions{0} {}
string to_string(ctensor tensor) {
    nimpl;
}