//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include <declarations.h>
#include <arrays/iterators.h>
#include <math/tensor_view.h>

#include <utility>

/** Tensor class for ML */
struct tensor {
    /* Fields */
    /** Elements of the tensor. */
    vec elements;
    /** Dimensions of the tensor. */
    dim dimensions;

    /* Properties */
    /** Number of dimensions in a tensor. Same as dimensions.size. */
    [[nodiscard]] inline nat rank() const { return dimensions.size; }

    /* Methods */
    /** Accesses element at indices at dimensions. */
    [[nodiscard]] scalar ref operator[](dim cref) const;
    /** Accesses element at index at flattened array. */
    [[nodiscard]] inline scalar ref operator[](nat i) const { return elements[i]; }

    /** Creates a tensor view with default tensor dimensions. */
    [[nodiscard]] tensor_view view() const;
    /** Creates a tensor view with custom order of dimensions. */
    [[nodiscard]]  tensor_view view(dim cref dimension_indices) const;

    /* Constructors */
    /** Creates zero tensor. */
    inline tensor() = default;
    /** Copies elements of another tensor. */
    inline tensor(tensor cref other) = default;
    /** Moves elements of another tensor. */
    inline tensor(tensor mref other) noexcept : move_init(elements, other), move_init(dimensions, other) {}

    /** Creates 1D tensor (vector_view) with numbers. */
    explicit tensor(vec elements);
    /** Creates 1D tensor (vector_view) with numbers. */
    inline tensor(params<scalar> numbers) : tensor(vec(numbers)) {}
    /** Creates a tensor with elements and specific dimensions. */
    tensor(vec elements, dim dimensions);
    /** Creates a tensor with elements and specific dimensions. */
    inline tensor(params<scalar> numbers, dim dimensions) : tensor(vec(numbers), std::move(dimensions)) {}
    /** Creates a tensor by flattening inner tensors. */
    tensor(params<tensor> tensors);


    /** Creates a tensor with specified dimensions, filled with the same value */
    static tensor of(scalar value, dim cref dimensions);
};

/* Operators*/

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
