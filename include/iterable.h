//
// Created by vlado on 3/2/20.
//

#ifndef CALCULUS_ITERABLE_H
#define CALCULUS_ITERABLE_H

#include "def.h"
#include "conversions.h"

#define __assert_splice_range(start, count, end, size) \
    assert(end <= size,\
    "Splice starting at " + start + " taking " + count + " elements overflows total number of elements. " +\
    end + " > " + size + ".")


/**
 * Selects elements from array, iterating in fixed step size, starting at offset.
 * @tparam T Vector data type.
 * @param source Source vector.
 * @param step Step size.
 * @param offset Starting index.
 * @return New vector with elements at selected indices.
 */
template<typename T>
vector<T> select(cvector<T> source, uint step = 1, uint offset = 0) {
    val size = source.size();

    vector<T> dest(size / step);

    var j{0};
    for (var i = offset; i < size; i += step)
        dest[j++] = source[i];

    return dest;
}
/**
 * Selects elements from array at specified indices.
 * @tparam T Vector data type.
 * @param source Source vector.
 * @param indices Indices vector.
 * @return New vector with elements at selected indices.
 */
template<typename T>
vector<T> select(cvector<T> source, cvnat indices) {
    val size = indices.size();

    vector<T> dest(size);

    for (var i{0u}; i < size; ++i)
        dest[i] = source[indices[i]];

    return dest;
}
/**
 * Returns a portion of a vector.
 * @tparam T Vector data type.
 * @param source Source vector.
 * @param start Start index. Specify negative number to count from the end.
 * @param count Remove count. Specify negative number to remove all elements from start.
 * @return Copy of array
 */
template<typename T>
vector<T> slice(cvector<T> source, int start = 0, int count = -1) {
    val size = source.size();

    val _start = to_uint(start >= 0 ? start : to_int(size) + start);

    if (_start >= size) error(ml_invalid_argument, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start);

    if (count < 0)
        return vector<T>(source.begin() + _start, source.end());

    return vector<T>(source.begin() + _start, source.begin() + _start + count);
}
/**
 * Removes range of elements from vector. Returns a copy.
 * @tparam T Vector data type.
 * @param source Source vector.
 * @param start Start index. Specify negative number to count from the end.
 * @param count Remove count. Specify negative number to remove all elements from start.
 * @return Copy of modified array.
 */
template<typename T>
vector<T> splice(cvector<T> source, int start, int count = 1) {
    val size = source.size();
    val _start = to_uint(start > 0 ? start : to_int(size) + start);

    if (count < 0) {
//        __assert_index(_start, size)

        return vector<T>(source.begin(), source.begin() + _start);
    }

    val _count = to_uint(count);
    val _end = _start + _count;

    __assert_splice_range(_start, _count, _end, size)

    vector<T> result(size - _count);

    for (var i = 0u; i < _start; ++i)
        result[i] = source[i];

    for (var i = 0u; i < _count; ++i)
        result[_start + i] = source[_end + i];

    return result;
}


#endif //CALCULUS_ITERABLE_H
