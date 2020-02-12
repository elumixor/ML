//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_CONVERSIONS_H
#define CALCULUS_CONVERSIONS_H


#include "declarations.h"

#define __cast(v, type) static_cast<type>((v))

#define to_int(v) __cast((v), int)
#define to_scalar(v) __cast((v), scalar)
#define to_nat(v) __cast((v), nat)

// Custom suffixes to convert to numeric type. These should always be used
inline constexpr scalar operator "" _n(long double d) {
    return to_scalar(d);
}
inline constexpr scalar operator "" _n(unsigned long long d) {
    return to_scalar(d);
}

#endif //CALCULUS_CONVERSIONS_H
