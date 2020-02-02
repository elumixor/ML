//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_ASSERTIONS_H
#define CALCULUS_ASSERTIONS_H

// todo: conditionally compile assertions with flag

/** We define assert as a macro to let message be lazily-evaluated */
#define __assert1(condition) if ((condition)) { ml_assertion_failed(default_assertion_message); }
#define __assert2(condition, message) if ((condition)) { ml_assertion_failed(printable(message)); }

// helper for overloading number of assert arguments
#define GET_MACRO(_1,_2,NAME,...) NAME
#define assert(...) GET_MACRO(__VA_ARGS__, __assert2, __assert1)(__VA_ARGS__)


#endif //CALCULUS_ASSERTIONS_H
