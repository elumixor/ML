//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_ASSERTIONS_H
#define CALCULUS_ASSERTIONS_H

#include "exceptions.h"
#include "output.h"

/** We define assert as a macro to let message be lazily-evaluated */
#define __assert1(condition) if (!(condition)) { throw ml_assertion_failed(); }
#define __assert2(condition, message) if (!(condition)) { throw ml_assertion_failed((printable::empty + message + "\n")); }
// helper for overloading number of assert arguments
#define GET_MACRO(_1, _2, NAME, ...) NAME

#ifdef ENABLE_ASSERTIONS
#define assert(...) GET_MACRO(__VA_ARGS__, __assert2, __assert1)(__VA_ARGS__)
#else
#define assert(...)
#endif
#endif //CALCULUS_ASSERTIONS_H
