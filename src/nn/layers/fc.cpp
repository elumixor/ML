//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#include <math/matht.h>
#include "nn/layers/fc.h"

// Constructors
fc::fc(nat batch_size, nat input_size, nat output_size, num weights_init, num bias_init) :
        weights({batch_size, output_size, input_size}, weights_init),
        bias({batch_size, output_size}, bias_init) {}
fc::fc(fc &&other) noexcept : move_init(weights, other), move_init(bias, other) {}


tensor fc::operator()(ctensor input) {
    // Assuming input is a 1D tensor (vector), extended to batch size
    // We get (covariant: batch, contravariant: vector)

    // Basic case is when weights is a 2D tensor (matrix), extended into third dimension (batch size)
    // Thus we get rank 3 tensor

    // So, weight transformation is a (1, 2)-tensor with components:
    // 1. Covariant: batch size, input size
    // 2. Contravariant: output size

    // Tensors component go as contravariant, covariant, contravariant, ...
    // Thus we initialize our weights as follows
    //  weights = tensor::random({batch_size, output_size, input_size});
    //  input is (batch_size, 1, input_size)
    return computed = dot(weights, input, 1, 2) + bias;
}
tensor fc::diff(const tensor &dl) {
//    dw = dl * computed;
//    dx = weights * computed;
    return tensor();
}
void fc::update(num learning_rate) {

}