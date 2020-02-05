//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#ifndef MACHINE_LEARNING_TO_STRING_H
#define MACHINE_LEARNING_TO_STRING_H

#include <declarations.h>
#include <math/tensor.h>
#include <nn/layer.h>
#include <nn/network.h>


/* to_string() declarations and template definitions */
/**
 * String representation of generic arr.
 * Internally calls to_string on arr elements.
 * Allows to specify custom opening bracket, closing bracket and separator
 * @tparam T Array elements type
 * @param arr Array of elements
 * @param opening Opening bracket (defaults to '[')
 * @param closing Closing bracket  (defaults to ']')
 * @param sep Separator (defaults to ", ")
 * @return String representation of an array
 */
template<typename T>
string to_string(carray<T> arr, char opening, char closing = ']', cstring sep = ", ") {
    string result{opening};

    val size{arr.size()};
    for (var i = 0u; i < size; ++i) {
        result += to_string(arr[i]);
        if (i < size - 1) result += sep;
    }
    result += closing;
    return result;
}
/**
 * String representation of generic array.
 * Internally calls to_string on array elements.
 * Allows to specify custom opening bracket, closing bracket and separator
 * @tparam T Array elements type
 * @param arr Array of elements
 * @param opening Opening bracket (defaults to '[')
 * @param closing Closing bracket  (defaults to ']')
 * @param sep Separator (defaults to ", ")
 * @return String representation of a array
 */
template<typename T>
string to_string(carray<T> arr, char opening, char closing, char sep) {
    return to_string(arr, opening, closing, to_string(sep));
}
/**
 * String representation of generic array.
 * Internally calls to_string on array elements.
 * Allows to specify custom opening bracket, closing bracket and separator
 * @tparam T Array elements type
 * @param arr Array of elements
 * @param opening Opening bracket (defaults to '[')
 * @param closing Closing bracket  (defaults to ']')
 * @param sep Separator (defaults to ", ")
 * @return String representation of a array
 */
template<typename T>
string to_string(carray<T> arr) {
    return to_string(arr, '[', ']', ", ");
}
/**
 * Generic string representation of a pointer to some object.
 * @tparam T Type of a pointer
 * @param data Pointer
 * @return String representation of pointer to an object
 */
template<typename T>
string to_string(const T *data) {
    char str[15];
    sprintf(str, "0x%x", data);
    return string("<") + string(typeid(*data).name()) + " at " + string(str) + ">";
}
/**
 * String representation of a tensor
 * @param tensor Tensor
 * @return String representation of a tensor
 */
string to_string(ctensor tensor);
/** String representation of a layer */
string to_string(clayer);
/** String representation of a network */
string to_string(cnetwork);

#endif //MACHINE_LEARNING_TO_STRING_H
