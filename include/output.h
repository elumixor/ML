//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_OUTPUT_H
#define CALCULUS_OUTPUT_H

#include "def.h"
#include "string_def.h"

struct printable {
    string str;

    printable() = default;
    template<typename T>
    printable(const T &arg): str{to_string(arg)} {}
    printable(string str);
    printable(const char *arg);
    void __print() const;
    operator string() const;
    printable &operator=(const string &x);
    static printable empty;
};

printable operator+(const printable &a, const printable &b);

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

#endif //CALCULUS_OUTPUT_H
