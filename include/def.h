//
// Created by vlado on 2/2/20.
// This file includes type definitions and aliases, used in project
//

#ifndef CALCULUS_DEF_H
#define CALCULUS_DEF_H

#include <string>
#include <vector>

// numeric type to be used
using num = float;

// alias for unsigned int
using uint = unsigned int;

// alias for str and const str reference
using string = std::string;
using cstring = const std::string &;


template<typename T>
using vector = std::vector<T>;
template<typename T>
using cvector = const std::vector<T> &;

struct tensor;
using ctensor = const tensor &;
struct ml_not_implemented;
struct printable;

printable operator "" _pr(const char *str, size_t);

namespace std {
    string to_string(ctensor tensor);

    template<typename T>
    string to_string(cvector<T> v, char opening = '[', char closing = ']', cstring sep = ", ") {
        string result{opening};

        const auto size{v.size()};
        for (uint i = 0; i < size; ++i) {
            result += to_string(v[i]);
            if (i < size - 1) result += sep;
        }
        result += closing;
        return result;
    }
}

#define to_string std::to_string

#endif //CALCULUS_DEF_H
