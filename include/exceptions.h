//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_EXCEPTIONS_H
#define CALCULUS_EXCEPTIONS_H

#include "def.h"
#include <exception>

/** Base for ML exceptions */
struct ml_exception : virtual public std::exception {
    string msg;
    explicit ml_exception(cstring msg = "ML Exception.") : msg{msg} {}
    virtual ~ml_exception() throw();
    virtual const char *what() const throw();
};

/** When assertion fails */
struct ml_assertion_failed : ml_exception {
    explicit ml_assertion_failed(cstring msg = "Assertion failed.") : ml_exception(msg) {}
};

struct ml_not_implemented : ml_exception {
    explicit ml_not_implemented(cstring msg = "Operation is not implemented.") : ml_exception(msg) {}
};

// not implemented exception
#define nimpl throw ml_not_implemented();

#endif //CALCULUS_EXCEPTIONS_H
