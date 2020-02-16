//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_PRINTABLE_H
#define CALCULUS_PRINTABLE_H

#include <common/declarations.h>

struct printable {
    string str;

    printable() = default;
    template<typename T>
    printable(T cref arg): str{to_string(arg)} {}
    printable(string str);
    printable(char cref c);
    printable(const char *arg);
    void __print() const;
    operator string() const;
    printable ref operator=(string cref x);

    static printable empty;
    static printable new_line;
};

printable operator+(printable cref a, printable cref b);
printable operator "" _pr(const char *str, size_t);

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
#define print(arg) (printable::empty + arg).__print()
#define print_line() printable::empty.__print()

#endif //CALCULUS_PRINTABLE_H
