//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_CONVERSIONS_H
#define CALCULUS_CONVERSIONS_H


#include "declarations.h"

#define __cast(v, type) static_cast<type>((v))

#define to_int(v) __cast((v), int)
#define to_num(v) __cast((v), num)
#define to_nat(v) __cast((v), nat)

#endif //CALCULUS_CONVERSIONS_H
