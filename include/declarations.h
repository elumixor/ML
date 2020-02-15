//
// Created by vlado on 2/2/20.
// This file includes type definitions and aliases, used in project
//

#ifndef CALCULUS_DEF_H
#define CALCULUS_DEF_H

#include <string>

/* Auto type declarations aliases */
/** Variable auto type */
#define var auto
/** Constant auto type */
#define val const auto
/** Variable auto type reference */
#define cvar auto &
/** Constant auto type reference */
#define cval const auto &

/* References */
#define ref &
#define cref const &
#define mref &&

/* Macros for copy and move initialization */
#define cinit(field, other) field{other.field}
#define cinits(field) field{field}
#define minit(field, other) field{std::move(other.field)}
#define minits(field) field{std::move(field)}

/* Macro for iteration */
#define forsize for(var i{0u}; i < size; ++i)

struct printable;

/* Type aliases */
/** Numeric type. (defaults to float) */
using num = float;
/** Natural number, used for indexing */
using nat = size_t;
/** Alias for std::string */
using string = std::string;
/** Alias for std::array<T> @tparam T data type */
/** Alias for initializer lise */
template<typename T> using params = std::initializer_list<T>;
/** Alias for std::to_string function */
using std::to_string;
using std::move;

#endif //CALCULUS_DEF_H
