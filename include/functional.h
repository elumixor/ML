//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_FUNCTIONAL_H
#define CALCULUS_FUNCTIONAL_H

#include "def.h"
#include "assertions.h"

#define __assert_vectors_same_size(a, b) assert(a.size() == b.size(), "Vectors should have same size. " + a.size() + " and " + b.size() + " received.")

template<typename T>
T mul(cvector<T> data) {
    if (data.size() < 1) return 0;
    T res{1};
    for (const auto &d : data)
        res *= d;
    return res;
}

template<typename T>
bool operator==(cvector<T> a, cvector<T> b) {
    auto size = a.size();
    if (b.size() != size) return false;

    for (uint i = 0; i < size; ++i) if (a[i] != b[i]) return false;

    return true;
}

/**
 * Dot product for two vectors
 * @tparam T Numeric type
 * @param a First vector
 * @param b Second vector
 * @return Number, dot product of a * b
 */
template<typename T>
T operator*(cvector<T> a, cvector<T> b) {
    __assert_vectors_same_size(a,b);

    auto size = a.size();
    T sum{0};
    for (auto i = 0u; i < size; ++i)
        sum += a[i] * b[i];

    return sum;
}


#endif //CALCULUS_FUNCTIONAL_H
