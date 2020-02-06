//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include <declarations.h>

/**
 * Tensor class for ML
 */
declare(tensor) {
    /* Fields */
    /** Tensor rank (number of dimensions) */
    nat rank{0};
    /** Tensor dimensions */
    vnat dimensions{};
    /** Numbers */
    vec elements{0};

    /* Properties */
    /** Number of elements in tensor */
    [[nodiscard]] inline nat size() const { return elements.size(); }
    /**
     * Returns element at index
     * @param index Array of indices on dimensions
     * @return Element at indices
     */
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
    [[nodiscard]] tensor subdim(nat dimension, nat offset, bool flatten = true) const;
    /**
     * Get specific sub-dimension. Returns a tensor, containing elements of that dimension.
     * @param component Index in dimension
     * @return Tensor, containing elements of that dimension.
     */
    [[nodiscard]] tensor operator[](nat component) const;

    /* Constructors */
    /** Creates a default (scalar) tensor of rank 0 with single zero element  */
    tensor();
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

    /* Copy and move*/
    tensor(ctensor);
    tensor(tensor &&) noexcept;
    tensor &operator=(ctensor);
    tensor &operator=(tensor &&) noexcept;

    /* Random tensors */
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
    /** Implicit conversion from vector */
    tensor(vec numbers);

    /* Indices iterable */
    declare(indices_iterable) {
        vnat dimensions;

        explicit indices_iterable(vnat dimensions);

        /* Iterator  */
        declare(indices_iterator) {
            cvnat dimensions;
            vnat indices;

            explicit indices_iterator(cvnat dimensions);
            indices_iterator(cvnat dimensions, vnat indices);

            cvnat operator*() const;
            const indices_iterator &operator++();
            bool operator!=(cindices_iterator) const;
        };

        [[nodiscard]] indices_iterator begin() const;
        [[nodiscard]] indices_iterator end() const;

    };

    /* Iterator yielding methods */
    inline indices_iterable indices() { return indices_iterable(dimensions); }
};

/* Operators*/

tensor operator+(ctensor a, ctensor b);
tensor &operator+=(tensor &a, ctensor b);
tensor operator-(ctensor a, ctensor b);
tensor operator+(ctensor a, num b);
tensor operator-(ctensor a, num b);
// hadamard product
tensor operator*(ctensor a, ctensor b);
tensor operator*(ctensor a, num b);
tensor operator*(num b, ctensor a);
tensor operator/(ctensor a, num b);

#endif //CALCULUS_TENSOR_H
