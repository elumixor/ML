//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#ifndef MACHINE_LEARNING_FC_H
#define MACHINE_LEARNING_FC_H

#include <nn/layer.h>

declare(fc) : layer {
    layer_name("fully connected");

    tensor weights;
    tensor bias;

    /* Constructors */
    fc(nat batch_size, nat input_size, nat output_size, num weights_init = 1, num bias_init = 0.5);
    fc(cfc &) = default;
    fc(fc &&) noexcept;
    /* Implementing layer */
    [[nodiscard]]
    inline layer *copy() const override { return new fc(*this); }
    tensor operator()(ctensor input) override;
    tensor diff(ctensor dl) override;
    void update(num learning_rate) override;
};

#endif //MACHINE_LEARNING_FC_H
