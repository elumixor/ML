//
// Created by Vladyslav Yazykov on 11/02/2020.
//

#ifndef MACHINE_LEARNING_ARR_H
#define MACHINE_LEARNING_ARR_H

#include "declarations.h"
#include "assertions.h"

/** Generic array of a fixed size. */
template<typename T>
struct arr {
    /** Iterator structure */
    struct arr_iterator {
        T *data;
        T ref operator*() const { return *data; }
        arr_iterator ref operator++() {
            data++;
            return *this;
        }
        bool operator!=(arr_iterator cref other) { return data != other.data; }
        explicit arr_iterator(T *data) : copy_init_s(data) {}
    };

    /* Fields */
    /** Size of the array. */
    nat size{0};
    /** Elements of the array. */
    T *elements{nullptr};

    /* Properties */
    /** Accesses element at index. */
    inline T &operator[](nat index) const {
        require(index < size, "Index (" + index + ") was out of bounds for array with size " + size);
        return elements[index];
    }
    /** Checks if array has any elements. */
    [[nodiscard]] inline bool empty() { return size == 0; }

    /* Constructors (defaults) */
    /** Creates an empty array of zero size. */
    arr() = default;
    /** Copies (deeply) elements of an existing array into a new one. */
    arr(arr cref other) : copy_init(size, other), elements{new T[size]} {
        for (auto i{0u}; i < size; ++i) elements[i] = other[i];
    }
    /** Moves elements of an existing array into a new one. */
    arr(arr mref other) noexcept : copy_init(size, other), copy_init(elements, other) {
        other.elements = nullptr;
        other.size = 0;
    }

    /* Constructors (from elements) */
    /** Creates an array from elements at location. */
    arr(T *elements, nat size) : copy_init_s(size), elements(new T[size]) {
        for (auto i{0u}; i < size; ++i) this->elements[i] = elements[i];
    }
    /** Creates an array from start address to end address. */
    arr(T *start, T *end) : size{end - start}, elements{new T[size]} {
        for (auto i{0u}; i < size; ++i) elements[i] = start[i];
    }
    /** Creates and array from an initializer list of elements. */
    arr(params<T> elements) : size{elements.size()}, elements{new T[size]} {
        val begin{elements.begin()};
        var i{0u};
        for (cval element : elements)
            this->elements[i++] = element;
    }

    /* Static constructors */
    /** Creates an array of a copy of the same element. */
    static arr of(nat size, T element) {
        arr result;
        result.size = size;
        result.elements = new T[size];
        for (auto i{0u}; i < size; ++i) result.elements[i] = element;
        return result;
    }

    /* Assignment operators */
    /** Copies (deeply) elements of an existing array into a new one. */
    arr &operator=(arr cref other) {
        if (this == &other)return *this;
        delete[](elements);

        size = other.size;
        elements = new T[size];

        for (auto i{0u}; i < size; ++i) elements[i] = other.elements[i];
    }
    /** Moves elements of an existing array into a new one. */
    arr &operator=(arr mref other) noexcept {
        if (this == &other)return *this;
        delete[](elements);

        size = other.size;
        elements = other.elements;

        other.size = 0;
        other.elements = nullptr;
    }

    /* Destructor */
    inline virtual ~arr() { delete[] elements; }

    /* Iteration */
    arr_iterator begin() { return arr_iterator(elements); }
    arr_iterator end() { return arr_iterator(elements + size); }
};

using dim = arr<nat>;
using vec = arr<scalar>;

#endif //MACHINE_LEARNING_ARR_H
