//
// Created by vlado on 2/2/20.
//

#include "../include/def.h"

template<>
string to_string(cvec vector) {
    nimpl
}

template<>
string to_string(cdim v) {
    string result{'['};

    const auto size{v.size()};
    for (uint i = 0; i < size; ++i) {
        result += to_string(v[i]);
        if (i < size - 1) result += ", ";
    }
    result += "]";
    return result;
}

string to_string(ctensor tensor) {
    return "tensor ("_pr + tensor.rank + "): " + tensor.dimensions;
}
