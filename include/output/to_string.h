//
// Created by Vladyslav Yazykov on 11/02/2020.
//

#ifndef MACHINE_LEARNING_TO_STRING_H
#define MACHINE_LEARNING_TO_STRING_H

#include <declarations.h>
#include <arrays/arrays.h>
#include <tensor.h>

/** String representation of a fixed generic array. */
template<typename T>
string to_string(view_struct<T> cref a, char opening_bracket = '[', char closing_bracket = ']', string cref separator = ", ") {
    string result{opening_bracket};

    for (cval item : a)
        result += to_string(item) + separator;

    val size{separator.length()};
    forsize result.pop_back();

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

string to_string(tensor cref tensor);
string to_string(tensor_view cref view);

#endif //MACHINE_LEARNING_TO_STRING_H
