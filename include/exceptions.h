//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_EXCEPTIONS_H
#define CALCULUS_EXCEPTIONS_H

#include "def.h"
#include <exception>
#include <utility>

#define __init_ml_exception ml_exception(file, line, msg)

/** Base for ML exceptions */
struct ml_exception : virtual public std::exception {
    string msg;

    ml_exception(cstring file, int line, cstring msg = "ML Exception.") : msg{
            msg + "\n\t" + file + ": " + to_string(line)} {}
    ~ml_exception() noexcept override;
    [[nodiscard]] const char *what() const noexcept override;
};

/** When assertion fails */
struct ml_assertion_failed : ml_exception {
    ml_assertion_failed(cstring file, int line, cstring msg = "Assertion failed.") : __init_ml_exception {}
};

struct ml_check_failed : ml_exception {
    ml_check_failed(cstring file, int line, cstring msg = "Invalid argument.")
            : __init_ml_exception {}
};

struct ml_not_implemented : ml_exception {
    ml_not_implemented(cstring file, int line, cstring msg = "Operation is not implemented.")
            : __init_ml_exception {}
};


#ifdef ENABLE_EXCEPTIONS
#define __error2(exception_type, message) throw exception_type(__FILE__, __LINE__, printable::empty + message)
#define __error1(exception_type) throw exception_type(__FILE__, __LINE__)

#define __get_error(_1, _2, NAME, ...) NAME
#define error(...) __get_error(__VA_ARGS__, __error2, __error1)(__VA_ARGS__)
#else
#define error(...)
#endif

// not implemented exception
#define nimpl error(ml_not_implemented);

#endif //CALCULUS_EXCEPTIONS_H
