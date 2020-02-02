//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include <vector>
#include "def.h"

using dim = vector<uint>;
using vec = vector<num>;
using cvec = const vec &;

/**
 * Tensor class
 */
struct tensor {
    uint rank;
    dim dimensions;
    vec data;

    tensor();
    tensor(vec data);
    tensor(cvec data, dim dimensions);

    static tensor ones(dim dimensions);
    static tensor zeros(dim dimensions);
    static tensor random(dim dimensions);
};

using ctensor = const tensor &;

#undef to_string
namespace std {
    string to_string(ctensor tensor);
}
#define to_string std::to_string

#endif //CALCULUS_TENSOR_H
