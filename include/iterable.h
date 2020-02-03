//
// Created by vlado on 3/2/20.
//

#ifndef CALCULUS_ITERABLE_H
#define CALCULUS_ITERABLE_H

#include "def.h"
#include "conversions.h"

#define assert_splice_size(start, size) assert(start < size, "Splice start index is greater then maximum index in array. " + start + " >= " + size)
#define assert_splice_range(start, count, end, size) \
    assert(end <= size,\
    "Splice starting at " + start + " taking " + count + " elements overflows total number of elements. " +\
    end + " > " + size + ".")

template<typename T>
vector<T> select(cvector<T> source, uint step = 1, uint offset = 0) {
    val size = source.size();

    vector<T> dest(size / step);

    var j{0};
    for (var i = offset; i < size; i += step)
        dest[j++] = source[i];

    return dest;
}


template<typename T>
vector<T> slice(cvector<T> source, uint start) {
    val size = source.size();
    val count{size - start};
    vector<T> dest(count);

    for (var i{0u}; i < count; i++)
        dest[i] = source[i + start];

    return dest;
}

template<typename T>
vector<T> slice(cvector<T> source, uint start, uint end) {
    val size = source.size();
    val count{end - start};
    vector<T> dest(count);

    for (var i{0u}; i < count; i++)
        dest[i] = source[i + start];

    return dest;
}

template<typename T>
vector<T> splice(cvector<T> source, int start, int count = 1) {
    val size = source.size();
    val _start = to_uint(start > 0 ? start : to_int(size) - start);

    if (count < 0) {
        assert_splice_size(_start, size)
        return vector<T>(source.begin() + _start, source.end());
    }

    val _count = to_uint(count);
    val _end = _start + _count;
    assert_splice_range(_start, _count, _end, size)

    vector<T> result(size - _count);
    for (var i = 0u; i < _start; ++i)
        result[i] = source[i];
    for (var i = 0u; i < _count; ++i)
        result[_start + i] = source[_end + i];

    return result;
}


#endif //CALCULUS_ITERABLE_H
