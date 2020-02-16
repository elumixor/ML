//
// Created by Vladyslav Yazykov on 11/02/2020.
//

#ifndef MACHINE_LEARNING_TO_STRING_H
#define MACHINE_LEARNING_TO_STRING_H

#include <common/declarations.h>
#include <collections/composite_index.h>
#include <collections/arrays.h>
#include <collections/tensor.h>

template<typename T>
string to_string(farray<T> cref a, char opening_bracket = '[', char closing_bracket = ']', string cref separator = ", ") {
    string result{opening_bracket};

    var count{0u};
    for (cval item : a) {
        result += to_string(item) + separator;
        count++;
    }

    if (count > 0) {
        val size{separator.length()};
        forsize result.pop_back();
    }

    result += closing_bracket;
    return result;
}
template<typename T>
string to_string(const T *data) {
    char str[15];
    sprintf(str, "0x%x", data);
    return string("<") + string(typeid(*data).name()) + " at " + string(str) + ">";
}

string to_string(tensor cref t);
string to_string(composite_index cref index);

#endif //MACHINE_LEARNING_TO_STRING_H
