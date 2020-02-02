//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include <vector>
#include "def.h"

using dim = vector<uint>;
using cdim = const dim &;
using vec = vector<num>;
using cvec = const vec &;

/**
 * Tensor class
 */
struct tensor {
    uint rank;
    dim dimensions;
    vec elements;

    tensor();
    tensor(vec elements);
    tensor(vec elements, dim dimensions);
    tensor(num element, dim dimensions);
};

using ctensor = const tensor &;

#undef to_string
namespace std {
    string to_string(ctensor tensor);
}
#define to_string std::to_string

#endif //CALCULUS_TENSOR_H
