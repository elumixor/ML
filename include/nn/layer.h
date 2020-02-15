//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#ifndef CALCULUS_LAYER_H
#define CALCULUS_LAYER_H


#include <declarations.h>
#include <math/tensor.h>

#define layer_name(n)                                                       \
    static constexpr const char *s_name{"[" n "]"};                         \
    /** Layer's name, accessed via instance, due to virtual inheritance */  \
    [[nodiscard]] const char *name() const override { return s_name; }      \

/**
 * Network's layer.
 * Contains a differentiable function (tensor -> tensor) and may or may not have learnable parameters.
 */
struct layer {
    /** Static layer's name */
    static constexpr const char *s_name{"[layer]"};
    /** Layer's name, accessed via instance, due to virtual inheritance */
    [[nodiscard]] virtual const char *name() const { return s_name; }

    /** Stored value of computation */
    tensor computed;

    /** Virtual destructor */
    virtual ~layer() = default;
    /**
     * Applies function to a tensor.
     * @param input Input tensor.
     * @return Transformed tensor.
     */
    virtual tensor operator()(tensor cref input) = 0;
    /**
     * Computes function derivative of a tensor object
     * @param dl Upstream loss derivative
     * @return
     */
    virtual tensor diff(tensor cref dl) = 0;
    /**
     * Updates module's learnable parameters by computed gradient, multiplied by learning rate.
     * @example W = W - gradient * learning_rate;
     * @param learning_rate Multiplier for the gradient
     */
    virtual void update(num learning_rate) = 0;
    /**
     * Creates a heap-allocated copy of a layer
     * @return Pointer to created copy
     */
    [[nodiscard]] virtual layer *copy() const = 0;
};

#endif //CALCULUS_LAYER_H
