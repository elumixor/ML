//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include "declarations.h"
#include "arrays/iterators.h"

/**
 * Tensor class for ML
 */
struct tensor {
    /* Fields */
    /** Elements of the tensor. */
    vec elements;
    /** Dimensions of the tensor. */
    dim dimensions;

    /* Methods */
    /** Accesses element at indices at dimensions. */
    [[nodiscard]] scalar ref operator[](dim cref) const;
    /** Accesses element at index at flattened array. */
    [[nodiscard]] inline scalar ref operator[](nat i) const { return elements[i]; }

    /* Constructors */
    /** Creates zero tensor. */
    inline tensor() = default;
    /** Copies elements of another tensor. */
    inline tensor(tensor cref other) = default;
    /** Moves elements of another tensor. */
    inline tensor(tensor mref other) noexcept : move_init(elements, other), move_init(dimensions, other) {}

    /** Creates 1D tensor (vector) with numbers. */
    explicit tensor(vec elements);
    /** Creates a tensor with elements and specific dimensions. */
    tensor(vec elements, dim dimensions);
    /** Creates a tensor by flattening inner tensors. */
    tensor(params<tensor> tensors);
    /** Creates a tensor by flattening inner vectors. */
    tensor(params<vec> vectors);

    /** Creates a tensor with specified dimensions, filled with the same value */
    static tensor of(scalar value, dim cref dimensions);
};

using ctensor = tensor cref;
//
///* Operators*/
//
//tensor operator-(tensor cref a);
//tensor operator+(tensor cref a, tensor cref b);
//tensor &operator+=(tensor ref a, tensor cref b);
//tensor &operator-=(tensor ref a, tensor cref b);
//tensor operator-(tensor cref a, tensor cref b);
//tensor operator+(tensor cref a, scalar b);
//tensor operator-(tensor cref a, scalar b);
//tensor operator*(tensor cref a, scalar b);
//tensor operator*(tensor cref a, tensor cref b); // hadamard
//tensor operator*(scalar b, tensor cref a);
//tensor operator/(tensor cref a, scalar b);
#endif //CALCULUS_TENSOR_H
