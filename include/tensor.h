//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include "def.h"
#include "assertions.h"

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
    tensor(std::initializer_list<num> elements);
    tensor(std::initializer_list<tensor> elements);
    tensor(dim dimensions, num element);

    num element(cdim index) const;
    vector<tensor> subdim() const;
};

tensor operator+(ctensor a, ctensor b);
tensor operator-(ctensor a, ctensor b);
tensor operator*(ctensor a, ctensor b);
tensor operator/(ctensor a, ctensor b);

inline tensor operator+(ctensor a, num b) {
    return a + tensor(a.dimensions, b);
}
inline tensor operator-(ctensor a, num b) {
    return a + -b;
}
inline tensor operator*(ctensor a, num b) {
    nimpl
}
inline tensor operator/(ctensor a, num b) {
    nimpl
}


#endif //CALCULUS_TENSOR_H
