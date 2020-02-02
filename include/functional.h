//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_FUNCTIONAL_H
#define CALCULUS_FUNCTIONAL_H

#include "def.h"

template<typename T>
T mul(cvector<T> data) {
    if (data.size() < 1) return 0;
    T res{1};
    for (const auto &d : data)
        res *= d;
    return res;
}

#endif //CALCULUS_FUNCTIONAL_H
