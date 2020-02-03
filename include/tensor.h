//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include "def.h"
#include "assertions.h"


/**
 *
 */

/**
 * Tensor class
 */
struct tensor {
    /* Fields */
    /** Tensor rank (number of dimensions) */
    uint rank;
    /** Tensor dimensions */
    vnat dimensions;
    /** Numbers */
    vec elements;

    /* Constructors */
    /**
     * Creates a tensor from tensors
     * @param tensors Array of tensors
     */
    tensor(std::initializer_list<tensor> tensors);
    /**
     * Creates a tensor from numbers
     * @param numbers Array of numbers
     */
    tensor(std::initializer_list<num> numbers);
    /**
     * Creates a tensor from elements with specific dimensions
     * @param numbers Array of numbers
     * @param dims Dimensions
     */
    tensor(vnat dims, vec numbers);
    /**
     * Creates a tensor from elements with specific dimensions
     * @param number Number, to be repeated
     * @param dims Dimensions
     */
    tensor(vnat dims, num number);
    /**
     * Creates a tensor of specific dimensions, with random elements, uniformly distributed
     * @param min Distribution minimum
     * @param max Distribution maximum
     * @return Created tensor
     */
    static tensor random(cvnat dimensions, num min = 0, num max = 1);
    /**
     * Creates a tensor of specific dimensions, with random elements, normally distributed
     * @param size Vector size
     * @param min Distribution mean
     * @param max Distribution standard deviation
     * @return Created tensor
     */
    static tensor random_normal(cvnat dimensions, num mean = 0.5, num std = .5);

    [[nodiscard]] num element(cvnat index) const;

    /* Sub-dimensions*/
    /**
     * Returns array of tensors, that comprise highest sub-dimension.
     * @return Array of tensors, that comprise highest sub-dimension.
     */
    [[nodiscard]] array<tensor> subdim() const;
    /**
     *
     * @param dimension
     * @param offset
     * @param flatten
     * @return
     */
    [[nodiscard]] tensor subdim(uint dimension, uint offset, bool flatten = true) const;
    /**
     * Get specific sub-dimension. Returns a tensor, containing elements of that dimension.
     * @param component Index in dimension
     * @return Tensor, containing elements of that dimension.
     */
    tensor operator[](uint component) const;

    /* Reshaping */
    /**
     * Reshapes a tensor to a new dimension in-place.
     * @param new_dim New dimensions.
     * @return Reference to reshaped tensor.
     */
    tensor &reshape(cvnat new_dim);

    /**
     * Reshapes a tensor to a new dimension. Returns a copy.
     * @param new_dim New dimensions.
     * @return Copy of a reshaped tensor.
     */
    [[nodiscard]] tensor reshaped(cvnat new_dim) const;

    /* Conversions */
    /** Converting tensor to a scalar. Works only for 0-rank tensors */
    explicit operator num() const;
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
