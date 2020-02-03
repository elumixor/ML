//
// Created by vlado on 2/2/20.
// This file includes type definitions and aliases, used in project
//

#ifndef CALCULUS_DEF_H
#define CALCULUS_DEF_H

#include <string>
#include <vector>

/* Auto type declarations aliases */
/**
 * Variable auto type
 */
#define var auto
/**
 * Constant auto type
 */
#define val const auto

/* Forward declarations */
struct ml_not_implemented;
struct printable;
struct tensor;

/* Type aliases */
/**
 * Numeric type. (defaults to float)
 */
using num = float;
/**
 * Alias for unsigned int type
 */
using uint = unsigned int;
/**
 * Alias for std::string
 */
using string = std::string;
/**
 * Alias for const string reference
 */
using cstring = const string &;
/**
 * Alias for std::array<T>
 * @tparam T data type
 */
template<typename T>
using array = std::vector<T>;
/**
 * Alias for const array reference
 */
template<typename T>
using carray = const std::vector<T> &;
/**
 * Numeric array. Alias for array<num>
 */
using vec = array<num>;
/**
 * Alias for const vec reference
 */
using cvec = const vec &;
/**
 * Array of uints. Is mainly used to describe indices
 */
using vnat = array<uint>;
/**
 * Alias for const vnat reference
 */
using cvnat = const vnat &;
/**
 * Alias for const tensor reference
 */
using ctensor = const tensor &;
/**
 * Alias for std::to_string function
 */
using std::to_string;

/* to_string() declarations and template definitions */
/**
 * String representation of a tensor
 * @param tensor Tensor
 * @return String representation of a tensor
 */
string to_string(ctensor tensor);
/**
 * String representation of generic arr. Internally calls to_string on arr elements.
 * Allows to specify custom opening bracket, closing bracket and separator
 * @tparam T Array elements type
 * @param arr Array of elements
 * @param opening Opening bracket (defaults to '[')
 * @param closing Closing bracket  (defaults to ']')
 * @param sep Separator (defaults to ", ")
 * @return String representation of a arr
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
 * String representation of generic array. Internally calls to_string on array elements.
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
 * String representation of generic array. Internally calls to_string on array elements.
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


#endif //CALCULUS_DEF_H
