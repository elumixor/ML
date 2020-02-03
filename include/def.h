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
 * Alias for std::vector<T>
 * @tparam T data type
 */
template<typename T>
using vector = std::vector<T>;
/**
 * Alias for const vector reference
 */
template<typename T>
using cvector = const std::vector<T> &;
/**
 * Numeric vector. Alias for vector<num>
 */
using vec = vector<num>;
/**
 * Alias for const vec reference
 */
using cvec = const vec &;
/**
 * Vector of uints. Is mainly used to describe indices
 */
using vnat = vector<uint>;
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
 * String representation of generic vector. Internally calls to_string on vector elements.
 * Allows to specify custom opening bracket, closing bracket and separator
 * @tparam T Vector elements type
 * @param vector Vector of elements
 * @param opening Opening bracket (defaults to '[')
 * @param closing Closing bracket  (defaults to ']')
 * @param sep Separator (defaults to ", ")
 * @return String representation of a vector
 */
template<typename T>
string to_string(cvector<T> vector, char opening, char closing = ']', cstring sep = ", ") {
    string result{opening};

    val size{vector.size()};
    for (var i = 0u; i < size; ++i) {
        result += to_string(vector[i]);
        if (i < size - 1) result += sep;
    }
    result += closing;
    return result;
}
/**
 * String representation of generic vector. Internally calls to_string on vector elements.
 * Allows to specify custom opening bracket, closing bracket and separator
 * @tparam T Vector elements type
 * @param vector Vector of elements
 * @param opening Opening bracket (defaults to '[')
 * @param closing Closing bracket  (defaults to ']')
 * @param sep Separator (defaults to ", ")
 * @return String representation of a vector
 */
template<typename T>
string to_string(cvector<T> vector, char opening, char closing, char sep) {
    return to_string(vector, opening, closing, to_string(sep));
}
/**
 * String representation of generic vector. Internally calls to_string on vector elements.
 * Allows to specify custom opening bracket, closing bracket and separator
 * @tparam T Vector elements type
 * @param vector Vector of elements
 * @param opening Opening bracket (defaults to '[')
 * @param closing Closing bracket  (defaults to ']')
 * @param sep Separator (defaults to ", ")
 * @return String representation of a vector
 */
template<typename T>
string to_string(cvector<T> vector) {
    return to_string(vector, '[', ']', ", ");
}


#endif //CALCULUS_DEF_H
