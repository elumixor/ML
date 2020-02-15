//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_MATHT_H
#define CALCULUS_MATHT_H

#include <declarations.h>
#include <math/tensor.h>
#include <assertions.h>
#include "arrays/arrays.h"


/**
 * Multiplies all elements of array together.
 * @tparam T Elements type.
 * @param data Array.
 * @return Product of all elements.
 */
template<typename T>
T product(farray<T> data) {
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
T sum(farray<T> data) {
    T res{0};
    for (const auto &d : data)
        res += d;
    return res;
}
template<typename T>
farray<T> operator-(farray<T> arr, T scalar) {
    val size{arr.size()};

    farray<T> result;
    result.resize(size);

    for (var i{0u}; i < size; ++i)
        result[i] = arr[i] - scalar;

    return result;
}
/**
 * Dot product for two vectors. Same as dot(a,b)
 * @tparam T Numeric type.
 * @param a First vector_view.
 * @param b Second vector_view.
 * @return Number, dot product of a * b.
 */
template<typename T>
T operator*(farray<T> a, farray<T> b) {
    require(a.size == b.size, "Arrays should have same size. " + a.size + " and " + b.size + " received.")

    auto size = a.size;
    T sum{0};
    forsize sum += a[i] * b[i];

    return sum;
}
/**
 * Dot product for two vectors. Same as a * b
 * @tparam T Numeric type.
 * @param a First vector_view.
 * @param b Second vector_view.
 * @return Number, dot product of a * b.
 */
template<typename T>
T dot(farray<T> a, farray<T> b) {
    return a * b;
}
/**
 * Dot product for two vectors. Same as a * b
 * @tparam T Numeric type.
 * @param a First vector_view.
 * @param b Second vector_view.
 * @return Number, dot product of a * b.
 */
template<typename T>
T dot(params<farray<T>> arrays) {
    farray<T> result{farray<T>::of(arrays.begin()->size, 1)};
    for (cval arr : arrays) {
        val size{arr.size};
        forsize result[i] *= arr[i];
    }

    return sum(result);
}
/**
 * Tensor dot product
 * @param a First tensor
 * @param b Second tensor
 * @param dim_a Dimension to sum over on a
 * @param dim_b Dimension to sum over on b
 */
//tensor dot(tensor cref a, tensor cref b, nat dim_a, nat dim_b);
/**
 * Tensor dot product
 * @param a First tensor
 * @param b Second tensor
 * @param dim_a Dimensions to sum over
 * @param dim_b Dimensions to sum over
 */
//tensor dot(tensor cref a, tensor cref b, dim cref dim_a, dim cref dim_b);
/**
 * Tensor (outer) product for vecotrs and tensors
 * @param a
 * @param b
 * @return
 */
//tensor outer(tensor cref a, tensor cref b);

/* Functions on tensors */
/** Sums all elements of a tensor */
//scalar sum(tensor_view cref t);
/** Sums tensors along dimensions */
//tensor sum(tensor cref t, nat dimension);
/** Average of all elements of a tensor */
//scalar mean(tensor cref t);
//tensor extend(tensor cref a, tensor cref b);
///** Multiplies elements of two tensors. */
//[[nodiscard]] tensor mul(tensor_view cref a, tensor_view cref b);
/** Multiplies elements of two tensors. */
//[[nodiscard]] tensor mul(tensor cref a, tensor cref b, dim cref, dim cref);
//[[nodiscard]] tensor dot(tensor_view cref a, tensor_view cref b);
#endif //CALCULUS_MATHT_H
