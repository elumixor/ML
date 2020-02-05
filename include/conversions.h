//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_CONVERSIONS_H
#define CALCULUS_CONVERSIONS_H


#include "def.h"

#define __cast(v, type) static_cast<type>((v))

#define to_int(v) __cast((v), int)
#define to_num(v) __cast((v), num)
#define to_nat(v) __cast((v), nat)

// Custom suffixes to convert to numeric type. These should always be used
inline constexpr num operator "" _n(long double d) {
    return to_num(d);
}
inline constexpr num operator "" _n(unsigned long long d) {
    return to_num(d);
}

#endif //CALCULUS_CONVERSIONS_H
