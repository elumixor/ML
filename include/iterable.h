////
//// Created by vlado on 3/2/20.
////
//
//#ifndef CALCULUS_ITERABLE_H
//#define CALCULUS_ITERABLE_H
//
//#include "declarations.h"
//#include "conversions.h"
//#include "assertions.h"
//#include <dim.h>
//
///* Reverse iterable */
//template<typename T>
//struct reversion_wrapper {
//    T &iterable;
//};
//template<typename T>
//auto begin(reversion_wrapper<T> w) { return std::rbegin(w.iterable); }
//template<typename T>
//auto end(reversion_wrapper<T> w) { return std::rend(w.iterable); }
///** Reversed iterator */
//template<typename T>
//reversion_wrapper<T> reverse(T &&iterable) { return {iterable}; }
//
///**
// * Compares two arrays element-wise.
// * @tparam T Elements type.
// * @param a First array.
// * @param b Second array.
// * @return True, if elements at same indices are equal.
// */
////template<typename T>
////bool operator==(carray<T> a, carray<T> b) {
////    auto size = a.size;
////    if (b.size != size) return false;
////
////    for (nat i = 0; i < size; ++i) if (a[i] != b[i]) return false;
////
////    return true;
////}
///**
// * Compares two arrays element-wise.
// * @tparam T Elements type.
// * @param a First array.
// * @param b Second array.
// * @return True, arrays have different length or have different elements at same indices
// */
////template<typename T>
////bool operator!=(carray<T> a, carray<T> b) { return !(a == b); }
///**
// * Creates an array with a range of numbers.
// * @tparam T Array data type.
// * @param count Total number of elements.
// * @param start Starting element.
// * @param step Difference between two elements.
// * @return Created array with a range of numbers.
// */
//template<typename T>
//array<T> range(nat count, T start = 0, T step = 1) {
//    array<T> result(count);
//    for (var i{0u}; i < count; ++i)
//        result[i] = start + step * i;
//
//    return result;
//}
///**
// * Creates a range of indices for array.
// */
//template<typename T>
//vnat indices(array<T> arr) { return range(arr.size); }
///** Returns true if source array contains specific element. */
//template<typename T>
//bool contains(carray<T> source, T element) {
//    for (cval item : source)
//        if (item == element) return true;
//
//    return false;
//}
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
// * Selects elements from array, iterating in fixed step size, starting at offset.
// * @tparam T Array data type.
// * @param source Source array.
// * @param step Step size.
// * @param offset Starting index.
// * @return New array with elements at selected indices.
// */
//template<typename T>
//array<T> select(carray<T> source, nat step = 1, nat offset = 0) {
//    val size = source.size;
//
//    array<T> dest(size / step);
//
//    var j{0};
//    for (var i = offset; i < size; i += step)
//        dest[j++] = source[i];
//
//    return dest;
//}
///**
// * Selects elements from array at specified indices.
// * @tparam T Array data type.
// * @param source Source array.
// * @param ind Indices array.
// * @return New array with elements at selected indices.
// */
//template<typename T>
//array<T> select(carray<T> source, dim cref ind) {
//    val size = ind.size;
//    check(source.size >= size, "Source size was smaller then selected indices size. " + source.size + " < " + size + ".")
//
//    array<T> dest(size);
//
//    for (var i{0u}; i < size; ++i)
//        dest[i] = source[ind[i]];
//
//    return dest;
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
//
//#endif //CALCULUS_ITERABLE_H
