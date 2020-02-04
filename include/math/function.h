//
// Created by vlado on 4/2/20.
//

#ifndef CALCULUS_FUNCTION_H
#define CALCULUS_FUNCTION_H


#include <def.h>

struct function {
    [[nodiscard]] virtual tensor forward(ctensor t) = 0;
    [[nodiscard]] virtual tensor backward(ctensor in, ctensor diff) = 0;
};


#endif //CALCULUS_FUNCTION_H
