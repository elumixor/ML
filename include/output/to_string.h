//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#ifndef MACHINE_LEARNING_TO_STRING_H
#define MACHINE_LEARNING_TO_STRING_H

#include <declarations.h>
#include <math/tensor.h>
#include <nn/layer.h>
#include <nn/network.h>
#include <index_iterable.h>

/** String representation of generic array. */
template<typename T>
string to_string(carray<T> arr, char opening_bracket = '[', char closing_bracket = ']', cstring separator = ", ") {
    string result{opening_bracket};

    val size{arr.size()};
    for (var i = 0u; i < size; ++i) {
        result += to_string(arr[i]);
        if (i < size - 1) result += separator;
    }
    result += closing_bracket;
    return result;
}
/** String representation of generic array. */
//template<typename T>
//string to_string(carray<T> arr, char opening_bracket, char closing_bracket, char separator) {
//    return to_string(arr, opening_bracket, closing_bracket, to_string(separator));
//}
///** String representation of generic array. */
//template<typename T>
//string to_string(carray<T> arr) {
//    return to_string(arr, '[', ']', ", ");
//}
/** String representation of a generic pointer. */
template<typename T>
string to_string(const T *data) {
    char str[15];
    sprintf(str, "0x%x", data);
    return string("<") + string(typeid(*data).name()) + " at " + string(str) + ">";
}
/** String representation of a tensor. */
string to_string(ctensor tensor);
/** String representation of a layer. */
string to_string(clayer);
/** String representation of a network. */
string to_string(cnetwork);
/** String representation of an index iterable. */
string to_string(c__indices_iterable);

#endif //MACHINE_LEARNING_TO_STRING_H
