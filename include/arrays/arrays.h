//
// Created by Vladyslav Yazykov on 11/02/2020.
//

#ifndef MACHINE_LEARNING_ARRAYS_H
#define MACHINE_LEARNING_ARRAYS_H

#include "declarations.h"
#include "conversions.h"
#include "assertions.h"

/** Iterator structure */
template<typename T>
struct array_view {
    const T *data;
    int step;
    T cref operator*() const { return *data; }
    array_view ref operator++() {
        data += step;
        return *this;
    }
    bool operator!=(array_view cref other) { return data != other.data; }
    explicit array_view(const T *data, int step = 1) : cinits(data), cinits(step) {}
};

template<typename T>
struct view_struct {
    /* Iteration */
    [[nodiscard]] virtual array_view<T> begin() const = 0;
    [[nodiscard]] virtual array_view<T> end() const = 0;
};

/** Generic array of a fixed size. */
template<typename T>
struct farray : view_struct<T> {
    /* Fields */
    /** Size of the array. */
    nat size{0};
    /** Elements of the array. */
    T *elements{nullptr};

    /* Methods */
    /** Accesses element at index. */
    [[nodiscard]] T &operator[](int index) const {
        if (index < 0) index = size + index;
        require(index < to_int(size), "Index (" + index + ") was out of bounds for array with size " + size);
        return elements[index];
    }
    /** Checks if array has any elements. */
    [[nodiscard]] bool empty() const { return size == 0; }
    /** Checks if array contains element. */
    [[nodiscard]] bool contains(T cref element) const {
        forsize if (elements[i] == element)
                return true;

        return false;
    }

    /* Constructors (defaults) */
    /** Creates an empty array of zero size. */
    farray() = default;
    /** Copies (deeply) elements of an existing array into a new one. */
    farray(farray cref other) : farray(other.size) { forsize elements[i] = other[i]; }
    /** Moves elements of an existing array into a new one. */
    farray(farray mref other) noexcept : cinit(size, other), cinit(elements, other) {
        other.elements = nullptr;
        other.size = 0;
    }

    /* Constructors (from elements) */
    /** Creates an array from elements at location. */
    farray(T *elements, nat size) : cinits(size), elements(new T[size]) { forsize this->elements[i] = elements[i]; }
    /** Creates an array from start address to end address. */
    farray(T *start, T *end) : size{end - start}, elements{new T[size]} { forsize elements[i] = start[i]; }
    /** Creates an array from an initializer list of elements. */
    farray(params<T> elements) : size{elements.size()}, elements{new T[size]} {
        val begin{elements.begin()};
        var i{0u};
        for (cval element : elements)
            this->elements[i++] = element;
    }
    /** Creates an array and allocates elements, without initializing them */
    farray(nat size) : cinits(size), elements(new T[size]) {}
    /** Creates an array of a copy of the same element. */
    farray(nat size, T element) : farray(size) { forsize elements[i] = element; }

    /* Static constructors */
    /** Creates a range of numbers */
    static farray range(nat size, T start = 0, T step = 1) {
        farray result;
        result.size = size;
        result.elements = new T[size];
        forsize result.elements[i] = start + (step * i);
        return result;
    }

    /* Assignment operators */
    /** Copies (deeply) elements of an existing array into a new one. */
    farray ref operator=(farray cref other) {
        if (this == ref other)return *this;
        delete[](elements);

        size = other.size;
        elements = new T[size];

        for (auto i{0u}; i < size; ++i) elements[i] = other.elements[i];
        return *this;
    }
    /** Moves elements of an existing array into a new one. */
    farray ref operator=(farray mref other) noexcept {
        if (this == ref other)return *this;
        delete[](elements);

        size = other.size;
        elements = other.elements;

        other.size = 0;
        other.elements = nullptr;
        return *this;
    }

    /* Destructor */
    virtual ~farray() { delete[] elements; }

    /* Iteration */
    [[nodiscard]] array_view<T> begin() const override { return array_view<T>(elements); }
    [[nodiscard]] array_view<T> end() const override { return array_view<T>(elements + size); }

    /* Operators */
    bool operator==(farray cref other) const {
        forsize if (elements[i] != other.elements[i])
                return false;

        return true;
    }
    bool operator!=(farray cref other) const { return !(*this == other); }
};

using dim = farray<nat>;
using idim = farray<int>;
using vec = farray<num>;

template<typename T>
[[nodiscard]] farray<T> select_at(farray<T> cref source, idim cref indices) {
    val size{indices.size};
    farray<T> result;
    result.size = size;
    result.elements = new T[size];
    forsize result[i] = source[indices[i]];
    return result;
}

template<typename T>
[[nodiscard]] farray<T> select_at(farray<T> cref source, dim cref indices) {
    val size{indices.size};
    farray<T> result;
    result.size = size;
    result.elements = new T[size];
    forsize result[i] = source[indices[i]];
    return result;
}

/** Forms dimension sizes from a dimensions */
dim dimensions_sizes(dim cref dimensions);

/** Concatenates two arrays. New array will have all elements of the first array, followed by all elements of a second. */
template<typename T>
farray<T> concat(farray<T> a, farray<T> b) {
    var size{a.size + b.size};
    farray<T> result(size);

    var i{0u};
    for (cval a1 : a)
        result[i++] = a1;
    for (cval b1 : b)
        result[i++] = b1;

    return result;
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
farray<T> slice(farray<T> cref source, int start = 0, int count = -1) {
    val size{source.size};
    val _start = to_nat(start >= 0 ? start : to_int(size) + start);

    check(_start <= size, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start)

    if (count < 0)
        return farray<T>(source.elements + start, size - start);

    return farray<T>(source.elements + _start, count);
}

#endif //MACHINE_LEARNING_ARRAYS_H
