////
//// Created by vlado on 2/2/20.
////
//
#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H
//
#include <declarations.h>
//
///**
// * Tensor class for ML
// */
struct tensor {
//    /* Fields */
//
//    scalar *elements;
//    nat *dimensions;
//    nat rank;
//
//    /* Properties */
//    [[nodiscard]] inline bool is_scalar() { return rank == 0; };
//
//    /* Constructors */
//    tensor();
//    tensor(tensor cref);
//    tensor(tensor mref) noexcept;
//
//    tensor(params<scalar> elements, params<nat> dims = {1});
//    tensor(params<tensor> tensors);
//
////    static of(scalar value, params)
//
//    /* Destructor */
//
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
