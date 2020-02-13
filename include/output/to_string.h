//
// Created by Vladyslav Yazykov on 11/02/2020.
//

#ifndef MACHINE_LEARNING_TO_STRING_H
#define MACHINE_LEARNING_TO_STRING_H

#include <declarations.h>
#include <arrays/arrays.h>

/** String representation of a fixed generic array. */
template<typename T>
string to_string(farray<T> cref a, char opening_bracket = '[', char closing_bracket = ']', string cref separator = ", ") {
    string result{opening_bracket};

    val size{a.size};

    forsize {
        result += to_string(a[i]);
        if (i < size - 1) result += separator;
    }

    result += closing_bracket;
    return result;
}
//string to_string
/** String representation of a generic pointer. */
template<typename T>
string to_string(const T *data) {
    char str[15];
    sprintf(str, "0x%x", data);
    return string("<") + string(typeid(*data).name()) + " at " + string(str) + ">";
}

#endif //MACHINE_LEARNING_TO_STRING_H
