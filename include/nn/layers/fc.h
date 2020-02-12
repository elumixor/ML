////
//// Created by Vladyslav Yazykov on 06/02/2020.
////
//
//#ifndef MACHINE_LEARNING_FC_H
//#define MACHINE_LEARNING_FC_H
//
//#include <nn/layer.h>
//
//struct fc : layer {
//    layer_name("fully connected");
//
//    tensor weights;
//    tensor bias;
//
//    tensor dw;
//    tensor db;
//
//    /* Constructors */
//    fc(nat batch_size, nat input_size, nat output_size, scalar weights_init = 1, scalar bias_init = 0.5);
////    fc(cfc &) = default;
//    fc(fc &&) noexcept;
//
//    /* Implementing layer */
////    [[nodiscard]] inline layer *copy() const override { return new fc(*this); }
//    tensor operator()(ctensor input) override;
//    tensor diff(ctensor dl) ;
//    void update(scalar learning_rate) ;
//};
//
//#endif //MACHINE_LEARNING_FC_H
