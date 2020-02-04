//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_MATHT_H
#define CALCULUS_MATHT_H

#include "def.h"
#include "assertions.h"

#define __assert_arrays_same_size(a, b) assert(a.size() == b.size(), "Arrays should have same size. " + a.size() + " and " + b.size() + " received.")

/**
 * Compares two arrays element-wise.
 * @tparam T Elements type.
 * @param a First array.
 * @param b Second array.
 * @return True, if elements at same indices are equal.
 */
template<typename T>
bool operator==(carray<T> a, carray<T> b) {
    auto size = a.size();
    if (b.size() != size) return false;

    for (uint i = 0; i < size; ++i) if (a[i] != b[i]) return false;

    return true;
}
/**
 * Multiplies all elements of array together.
 * @tparam T Elements type.
 * @param data Array.
 * @return Product of all elements.
 */
template<typename T>
T product(carray<T> data) {
    T res{1};
    for (const auto &d : data)
        res *= d;
    return res;
}
/**
 * Adds all elements of array together.
 * @tparam T Elements type.
 * @param data Array.
 * @return Sum of all elements.
 */
template<typename T>
T sum(carray<T> data) {
    T res{0};
    for (const auto &d : data)
        res += d;
    return res;
}
/**
 * Dot product for two vectors.
 * @tparam T Numeric type.
 * @param a First vector.
 * @param b Second vector.
 * @return Number, dot product of a * b.
 */
template<typename T>
T operator*(carray<T> a, carray<T> b) {
    __assert_arrays_same_size(a, b);

    auto size = a.size();
    T sum{0};
    for (auto i = 0u; i < size; ++i)
        sum += a[i] * b[i];

    return sum;
}

/* Functions on tensors */
/** Sum of elements of a tensor */
num sum(ctensor t);
/** Average of all elements of a tensor */
num mean(ctensor t);


#endif //CALCULUS_MATHT_H
