//
// Created by Vladyslav Yazykov on 12/02/2020.
//

#ifndef MACHINE_LEARNING_ITERATORS_H
#define MACHINE_LEARNING_ITERATORS_H

#include <arrays/arrays.h>

/* Indices iterable. Takes a dim (array of nat numbers) */
struct composite_index {
    /* Iterator  */
    struct iterator {
        dim cref maximum;
        dim current;

        explicit iterator(dim cref maximum) : cinits(maximum), current(maximum.size, 0) {}
        iterator(dim cref maximum, dim current) : cinits(maximum), minits(current) {}

        inline dim cref operator*() const { return current; }
        inline bool operator!=(iterator cref other) const { return current != other.current; }
        const iterator &operator++();
    };

    dim dimensions;
    dim current_index;
    dim sizes;

    composite_index(dim dimensions, dim current_index)
            : minits(dimensions), minits(current_index), sizes(dimensions_sizes(this->dimensions)) {}
    explicit composite_index(dim cref dimensions) : composite_index(dimensions, dim(dimensions.size, 0)) {}

    [[nodiscard]] nat unwrapped() const;
    [[nodiscard]] nat unwrapped(dim cref dimension_sizes) const;
    dim operator[](nat i) const;
    composite_index ref operator++();

    [[nodiscard]] inline iterator begin() const { return iterator(dimensions, current_index); }
    [[nodiscard]] inline iterator end() const {
        dim d(dimensions.size, 0);
        d[0] = dimensions[0] + 1;
        return iterator(dimensions, d);
    }

    static nat form_index(dim cref index, dim cref sizes);
};

template<typename T>
struct reverse : view_struct<T> {
    const T *start;
    nat size;

    explicit reverse(farray<T> cref array) : start{array.elements}, size{array.size} {}

    [[nodiscard]] array_view<T> begin() const { return array_view<T>(start + size - 1, -1); }
    [[nodiscard]] array_view<T> end() const { return array_view<T>(start - 1); }
};


template<typename T>
struct select : view_struct<T> {
    const T *data;
    const nat step;
    const nat count;

    select(farray<T> cref array, nat step = 1, nat offset = 0)
            : data{array.elements + offset}, cinits(step), count{(array.size - offset) / step} {}
    select(const T *data, nat step, nat count) : cinits(data), cinits(step), cinits(count) {}

    [[nodiscard]] T cref operator[](int index) const {
        if (index < 0) index = count + index;
        return data[step * index];
    }

    [[nodiscard]] array_view<T> begin() const { return array_view<T>(data, step); }
    [[nodiscard]] array_view<T> end() const { return array_view<T>(data + (step * count)); }
};


//template<typename T>
//std::tuple<array<T>, array<T>> split(carray<T> arr, nat split_index) {
//    val s2{arr.size - split_index};
//
//    array<T> a1;
//    array<T> a2;
//
//    a1.reserve(split_index);
//    a2.reserve(s2);
//
//    for (var i{0u}; i < split_index; ++i)
//        a1.push_back(arr[i]);
//    for (var i{0u}; i < s2; ++i)
//        a2.push_back(arr[split_index + i]);
//
//    return {a1, a2};
//}
///**
// * Selects elements from array except elements at specified indices.
// * @tparam T Array data type.
// * @param source Source array.
// * @param ind Indices array.
// * @return New array with elements without elements at selected indices.
// */
//template<typename T>
//array<T> unselect(carray<T> source, dim cref ind) {
//    val size = source.size;
//    val ind_size{ind.size};
//
//    if (size == ind_size) return {};
//
//    check(size >= ind_size, "Source size was smaller then selected indices size. " + size + " < " + ind_size + ".")
//    array<T> dest;
//    dest.reserve(size - ind_size);
//
////    for (var i{0u}; i < size; ++i)
////        if (!contains<nat>(ind, i))
////            dest.push_back(source[i]);
//
//    return dest;
//}
///**
// * Flattens array of arrays into a single one through concatenation.
// */
//template<typename T>
//array<T> flatten(carray<carray<T>> arrays) {
//    var size{0u};
//    for (cval arr : arrays)
//        size += arr.size;
//
//    array<T> result;
//    result.reserve(size);
//
//    for (cval arr : arrays)
//        result.insert(result.end(), arr.begin(), arr.end());
//
//    return result;
//}
///**
// * Concatenates two arrays. New array will have all elements of the first array, followed by all elements of a second.
// */
//template<typename T>
//array<T> concat(carray<T> a, carray<T> b) {
//    var size{a.size + b.size};
//
//    array<T> result;
//    result.reserve(size);
//
//    result.insert(result.end(), a.begin(), a.end());
//    result.insert(result.end(), b.begin(), b.end());
//
//    return result;
//}
///**
// * Returns a portion of a array.
// * @tparam T Array data type.
// * @param source Source array.
// * @param start Start index. Specify negative number to count from the end.
// * @param count Remove count. Specify negative number to remove all elements from start.
// * @return Copy of array
// */
//template<typename T>
//array<T> slice(carray<T> source, int start = 0, int count = -1) {
//    val size = source.size;
//    val _start = to_nat(start >= 0 ? start : to_int(size) + start);
//
//    check(_start <= size, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start)
//
//    if (count < 0)
//        return array<T>(source.begin() + _start, source.end());
//
//    return array<T>(source.begin() + _start, source.begin() + _start + count);
//}
///**
// * Removes range of elements from array. Returns a copy.
// * @tparam T Array data type.
// * @param source Source array.
// * @param start Start index. Specify negative number to count from the end.
// * @param count Remove count. Specify negative number to remove all elements from start.
// * @return Copy of modified array.
// */
//template<typename T>
//array<T> splice(carray<T> source, int start, int count = 1) {
//    val size = source.size;
//    val _start = to_nat(start >= 0 ? start : to_int(size) + start);
//
//    check(_start < size, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start)
//
//    if (count < 0)
//        return array<T>(source.begin(), source.begin() + _start);
//
//    val _count = to_nat(count);
//    val _end{_start + _count};
//
//    check(_end <= size, "Splice end's index was out of bounds. " + _start + " + " + _count + " = " + _end + " > " + size + ".")
//
//    array<T> result(size - _count);
//
//    for (var i = 0u; i < _start; ++i)
//        result[i] = source[i];
//
//    for (var i = _end; i < size; ++i)
//        result[i - _count] = source[i];
//
//    return result;
//}

#endif //MACHINE_LEARNING_ITERATORS_H
