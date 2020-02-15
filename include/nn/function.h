//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#ifndef CALCULUS_FUNCTION_H
#define CALCULUS_FUNCTION_H


#include <declarations.h>
#include "layer.h"

/**
 * Module without learnable parameters
 */
struct function : layer {
/** Update on a function has no effect, because function has no learnable parameters. */
    void update(num) final;
};

#endif //CALCULUS_FUNCTION_H
