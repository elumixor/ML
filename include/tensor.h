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
    /**
     * Tensor rank (number of dimensions)
     */
    uint rank;
    /**
     * Tensor dimensions
     */
    vnat dimensions;
    vec elements;

    /**
     * Create tensor from elements (scalars)
     * @param elements Scalar numbers
     */
    tensor(std::initializer_list<num> elements);
    /**
     * Create tensor from elements (tensors)
     * @param elements Nested tensors
     */
    tensor(std::initializer_list<tensor> elements);
    // From elements with specific dimensions
    tensor(vec elements, vnat dimensions);
    // Same element repeated
    tensor(num element, cvnat dimensions);

    [[nodiscard]] num element(cvnat index) const;
    [[nodiscard]] vector<tensor> subdim() const;
    [[nodiscard]] tensor subdim(uint dimension, uint offset, bool flatten = true) const;

    /** In-place reshaping */
    tensor &reshape(cvnat new_dim);

    /** Reshaping, that returns a copy */
    [[nodiscard]] tensor reshaped(cvnat new_dim) const;

    /** Converting tensor to a scalar. Works only for 0-rank tensors  */
    operator num() const;

    /** Get specific sub-dimension */
    tensor operator[](uint dim) const;
};

tensor operator+(ctensor a, ctensor b);
tensor operator-(ctensor a, ctensor b);
tensor operator*(ctensor a, ctensor b);
tensor operator/(ctensor a, ctensor b);

inline tensor operator+(ctensor a, num b) {
    return a + tensor(b, a.dimensions);
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
