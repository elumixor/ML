//
// Created by vlado on 3/2/20.
//

#ifndef CALCULUS_ITERABLE_H
#define CALCULUS_ITERABLE_H

#include "def.h"
#include "conversions.h"
#include "assertions.h"

/**
 * Selects elements from array, iterating in fixed step size, starting at offset.
 * @tparam T Array data type.
 * @param source Source array.
 * @param step Step size.
 * @param offset Starting index.
 * @return New array with elements at selected indices.
 */
template<typename T>
array<T> select(carray<T> source, uint step = 1, uint offset = 0) {
    val size = source.size();

    array<T> dest(size / step);

    var j{0};
    for (var i = offset; i < size; i += step)
        dest[j++] = source[i];

    return dest;
}
/**
 * Selects elements from array at specified indices.
 * @tparam T Array data type.
 * @param source Source array.
 * @param indices Indices array.
 * @return New array with elements at selected indices.
 */
template<typename T>
array<T> select(carray<T> source, cvnat indices) {
    val size = indices.size();

    array<T> dest(size);

    for (var i{0u}; i < size; ++i)
        dest[i] = source[indices[i]];

    return dest;
}
/**
 * Returns a portion of a array.
 * @tparam T Array data type.
 * @param source Source array.
 * @param start Start index. Specify negative number to count from the end.
 * @param count Remove count. Specify negative number to remove all elements from start.
 * @return Copy of array
 */
template<typename T>
array<T> slice(carray<T> source, int start = 0, int count = -1) {
    val size = source.size();
    val _start = to_uint(start >= 0 ? start : to_int(size) + start);

    check(_start <= size, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start)

    if (count < 0)
        return array<T>(source.begin() + _start, source.end());

    return array<T>(source.begin() + _start, source.begin() + _start + count);
}
/**
 * Removes range of elements from array. Returns a copy.
 * @tparam T Array data type.
 * @param source Source array.
 * @param start Start index. Specify negative number to count from the end.
 * @param count Remove count. Specify negative number to remove all elements from start.
 * @return Copy of modified array.
 */
template<typename T>
array<T> splice(carray<T> source, int start, int count = 1) {
    val size = source.size();
    val _start = to_uint(start >= 0 ? start : to_int(size) + start);

    check(_start < size, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start)

    if (count < 0)
        return array<T>(source.begin(), source.begin() + _start);

    val _count = to_uint(count);
    val _end{_start + _count};

    check(_end <= size, "Splice end's index was out of bounds. " + _start + " + " + _count + " = " + _end + " > " + size + ".")

    array<T> result(size - _count);

    for (var i = 0u; i < _start; ++i)
        result[i] = source[i];

    for (var i = _end; i < size; ++i)
        result[i - _count] = source[i];

    return result;
}

/* Random vectors */
/**
 * Creates a vector with random numbers, uniformly distributed
 * @param size Vector size
 * @param min Distribution minimum
 * @param max Distribution maximum
 * @return Vector with random numbers
 */
vec vec_uniform(uint size, num min = 0, num max = 1);
/**
 * Creates a vector with random numbers, normally distributed
 * @param size Vector size
 * @param min Distribution mean
 * @param max Distribution standard deviation
 * @return Vector with random numbers
 */
vec vec_normal(uint size, num mean = .5, num std = .5);
#endif //CALCULUS_ITERABLE_H
