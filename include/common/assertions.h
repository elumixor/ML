//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_ASSERTIONS_H
#define CALCULUS_ASSERTIONS_H

#include <common/declarations.h>
#include <common/exceptions.h>
#include <output/printable.h>

/** We define require as a macro to let message be lazily-evaluated */
#ifdef ENABLE_ASSERTIONS

#define __assert1(condition) if (!(condition)) { error(ml_assertion_failed); }
#define __assert2(condition, message) if (!(condition)) { error(ml_assertion_failed, (printable::empty + message + printable::new_line)); }
#define __get_assertion(_1, _2, NAME, ...) NAME
#define require(...) __get_assertion(__VA_ARGS__, __assert2, __assert1)(__VA_ARGS__)

#else
#define require(...)
#endif

#define __check1(condition) if (!(condition)) { error(ml_check_failed); }
#define __check2(condition, message) if (!(condition)) { error(ml_check_failed, (printable::empty + message + printable::new_line)); }
#define __get_check(_1, _2, NAME, ...) NAME
#define check(...) __get_check(__VA_ARGS__, __check2, __check1)(__VA_ARGS__)


#endif //CALCULUS_ASSERTIONS_H
