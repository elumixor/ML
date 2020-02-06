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

#define copy_init(field, other) field{other.field}
#define copy_init_s(field) field{field}
#define move_init(field, other) field{std::move(other.field)}
#define move_init_s(field) field{std::move(field)}

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
template<typename T> using params = std::initializer_list<T>;
/** Numeric array. Alias for array<num> */
alias(vec, array<num>);
/** Array of natural numbers. Is mainly used to describe indices */
alias(vnat, array<nat>);
/** Alias for std::to_string function */
using std::to_string;

#endif //CALCULUS_DEF_H
