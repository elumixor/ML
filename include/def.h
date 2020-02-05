//
// Created by vlado on 2/2/20.
// This file includes type definitions and aliases, used in project
//

#ifndef CALCULUS_DEF_H
#define CALCULUS_DEF_H

#include <string>
#include <vector>

/* Auto type declarations aliases */
/** Variable auto type */
#define var auto
/** Constant auto type */
#define val const auto
/** Variable auto type reference */
#define cvar auto &
/** Constant auto type reference */
#define cval const auto &

/* Macros for defining structs with aliasing for const reference */
#define __cref(type) using c ## type = const type &
#define declare(type) struct type; __cref(type); struct type
#define alias(new_type, aliased_type) using new_type = aliased_type; __cref(new_type)

/* Macro to */
#define copy_override(base_type, self_type)         \
[[nodiscard]] base_type *copy() const override {    \
    return new self_type(*this);                    \
}

/* Forward declarations */
struct ml_not_implemented;
struct printable;

/* Type aliases */
/** Numeric type. (defaults to float) */
alias(num, float);
/** Natural number, used for indexing */
alias(nat, size_t);
/** Alias for std::string */
alias(string, std::string);
/** Alias for std::array<T> @tparam T data type */
template<typename T> using array = std::vector<T>;
/** Alias for const array reference */
template<typename T> using carray = const std::vector<T> &;
/** Alias for initializer lise */
template<typename T> using params=std::initializer_list<T>;
/** Numeric array. Alias for array<num> */
alias(vec, array<num>);
/** Array of natural numbers. Is mainly used to describe indices */
alias(vnat, array<nat>);
/** Alias for std::to_string function */
using std::to_string;

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
template<typename T>
string to_string(const T *data) {
    char str[15];
    sprintf(str, "0x%x", data);
    return string("<") + string(typeid(*data).name()) + " at " + string(str) + ">";
}


#endif //CALCULUS_DEF_H
