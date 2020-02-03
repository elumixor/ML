//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_ASSERTIONS_H
#define CALCULUS_ASSERTIONS_H

#include "exceptions.h"
#include "output.h"

/** We define assert as a macro to let message be lazily-evaluated */
#ifdef ENABLE_ASSERTIONS

#define __assert1(condition) if (!(condition)) { error(ml_assertion_failed); }
#define __assert2(condition, message) if (!(condition)) { error(ml_assertion_failed, (printable::empty + message + printable::new_line)); }
#define __get_assertion(_1, _2, NAME, ...) NAME
#define assert(...) __get_assertion(__VA_ARGS__, __assert2, __assert1)(__VA_ARGS__)

#else
#define assert(...)
#endif
#endif //CALCULUS_ASSERTIONS_H
