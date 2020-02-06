//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_MATHT_H
#define CALCULUS_MATHT_H

#include <declarations.h>
#include <math/tensor.h>
#include <assertions.h>

#define __require_arrays_same_size(a, b) require(a.size() == b.size(), "Arrays should have same size. " + a.size() + " and " + b.size() + " received.")

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
template<typename T>
array<T> operator-(carray<T> arr, T scalar) {
    val size{arr.size()};

    array<T> result;
    result.resize(size);

    for (var i{0u}; i < size; ++i)
        result[i] = arr[i] - scalar;

    return result;
}
/**
 * Dot product for two vectors. Same as dot(a,b)
 * @tparam T Numeric type.
 * @param a First vector.
 * @param b Second vector.
 * @return Number, dot product of a * b.
 */
template<typename T>
T operator*(carray<T> a, carray<T> b) {
    __require_arrays_same_size(a, b);

    auto size = a.size();
    T sum{0};
    for (auto i = 0u; i < size; ++i)
        sum += a[i] * b[i];

    return sum;
}
/**
 * Dot product for two vectors. Same as a * b
 * @tparam T Numeric type.
 * @param a First vector.
 * @param b Second vector.
 * @return Number, dot product of a * b.
 */
template<typename T>
T dot(carray<T> a, carray<T> b) {
    return a * b;
}
/**
 * Tensor dot product
 * @param a First tensor
 * @param b Second tensor
 * @param dim_a Dimension to sum over on a
 * @param dim_b Dimension to sum over on b
 * @return
 */
tensor dot(ctensor a, ctensor b, nat dim_a, nat dim_b);
/**
 * Tensor (outer) product for vecotrs and tensors
 * @param a
 * @param b
 * @return
 */
tensor outer(ctensor a, ctensor b);

/* Functions on tensors */
/** Sum of elements of a tensor */
num sum(ctensor t);
/** Average of all elements of a tensor */
num mean(ctensor t);

/* Random vectors */
/**
 * Creates a vector with random numbers, uniformly distributed
 * @param size Vector size
 * @param min Distribution minimum
 * @param max Distribution maximum
 * @return Vector with random numbers
 */
vec vec_uniform(nat size, num min = 0, num max = 1);
/**
 * Creates a vector with random numbers, normally distributed
 * @param size Vector size
 * @param min Distribution mean
 * @param max Distribution standard deviation
 * @return Vector with random numbers
 */
vec vec_normal(nat size, num mean = .5, num std = .5);

#endif //CALCULUS_MATHT_H
