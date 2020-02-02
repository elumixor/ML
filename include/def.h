//
// Created by vlado on 2/2/20.
// This file includes type definitions and aliases, used in project
//

#ifndef CALCULUS_DEF_H
#define CALCULUS_DEF_H

#include <string>

// numeric type to be used
using num = float;

// alias for unsigned int
using uint = unsigned int;

// alias for str and const str reference
using string = std::string;
using cstring =const std::string &;

/** Converts object to string */
#define to_string std::to_string

/**
 * Tensor class
 */
struct tensor;
using ctensor = const tensor &;

// Printing functions
#include "printable.h"

/**
 * Logging, that is only called if ENABLE_LOGGING is defined
 */
#if ENABLE_LOGGING
#define log(arg) printable(printable::empty + arg).__print()
#else
#define log(arg)
#endif


/**
 * Printing, that always outputs to console
 */
#define print(arg) printable(printable::empty + arg).__print()


// casts
#define __cast(v, type) static_cast<type>((v))

#define to_int(v) __cast((v), int)
#define to_num(v) __cast((v), num)

// custom suffix to
inline constexpr num operator "" _n(long double d) {
    return to_num(d);
}
inline constexpr num operator "" _n(unsigned long long d) {
    return to_num(d);
}

#endif //CALCULUS_DEF_H
