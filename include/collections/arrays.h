//
// Created by Vladyslav Yazykov on 11/02/2020.
//

#ifndef MACHINE_LEARNING_ARRAYS_H
#define MACHINE_LEARNING_ARRAYS_H

#include "common/declarations.h"
#include "common/conversions.h"
#include "common/assertions.h"

/** Generic collections of a fixed size. */
template<typename T>
struct farray {
    struct view {
        const T *data;
        const nat step;
        const nat count;

        struct iterator {
            const T *data;
            int step;
            T cref operator*() const { return *data; }
            iterator ref operator++() {
                data += step;
                return *this;
            }
            bool operator!=(iterator cref other) { return data != other.data; }
            explicit iterator(const T *data, int step = 1) : cinits(data), cinits(step) {}
        };

        explicit view(farray<T> cref array, nat step = 1, nat offset = 0)
                : data{array.elements + offset}, cinits(step), count{(array.size - offset) / step} {}
        view(const T *data, nat step, nat count) : cinits(data), cinits(step), cinits(count) {}

        [[nodiscard]] T cref operator[](int index) const {
            if (index < 0) index = count + index;
            return data[step * index];
        }

        [[nodiscard]] iterator begin() const { return iterator(data, step); }
        [[nodiscard]] iterator end() const { return iterator(data + (step * count)); }
    };

    /* Fields */
    /** Size of the collections. */
    nat size{0};
    /** Elements of the collections. */
    T *elements{nullptr};

    /* Methods */
    /** Accesses element at index. */
    [[nodiscard]] T &operator[](int index) const {
        if (index < 0) index = size + index;
        require(index < to_int(size), "Index (" + index + ") was out of bounds for collections with size " + size);
        return elements[index];
    }
    /** Checks if collections has any elements. */
    [[nodiscard]] bool empty() const { return size == 0; }
    /** Checks if collections contains element. */
    [[nodiscard]] bool contains(T cref element) const {
        forsize if (elements[i] == element)
                return true;

        return false;
    }

    /* Constructors (defaults) */
    /** Creates an empty collections of zero size. */
    farray() = default;
    /** Copies (deeply) elements of an existing collections into a new one. */
    farray(farray cref other) : farray(other.size) { forsize elements[i] = other[i]; }
    /** Moves elements of an existing collections into a new one. */
    farray(farray mref other) noexcept : cinit(size, other), cinit(elements, other) {
        other.elements = nullptr;
        other.size = 0;
    }

    /* Constructors (from elements) */
    /** Creates an collections from elements at location. */
    farray(T *elements, nat size) : cinits(size), elements(new T[size]) { forsize this->elements[i] = elements[i]; }
    /** Creates an collections from start address to end address. */
    farray(T *start, T *end) : size{end - start}, elements{new T[size]} { forsize elements[i] = start[i]; }
    /** Creates an collections from an initializer list of elements. */
    farray(params<T> elements) : size{elements.size()}, elements{new T[size]} {
        val begin{elements.begin()};
        var i{0u};
        for (cval element : elements)
            this->elements[i++] = element;
    }
    /** Creates an collections and allocates elements, without initializing them */
    explicit farray(nat size) : cinits(size), elements(new T[size]) {}
    /** Creates an collections of a copy of the same element. */
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
    /** Copies (deeply) elements of an existing collections into a new one. */
    farray ref operator=(farray cref other) {
        if (this == ref other)return *this;
        delete[](elements);

        size = other.size;
        elements = new T[size];

        for (auto i{0u}; i < size; ++i) elements[i] = other.elements[i];
        return *this;
    }
    /** Moves elements of an existing collections into a new one. */
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
    [[nodiscard]] typename view::iterator begin() const { return typename view::iterator(elements); }
    [[nodiscard]] typename view::iterator begin() { return typename view::iterator(elements); }
    [[nodiscard]] typename view::iterator end() const { return typename view::iterator(elements + size); }
    [[nodiscard]] typename view::iterator end() { return typename view::iterator(elements + size); }

    /* Operators */
    bool operator==(farray cref other) const {
        forsize if (elements[i] != other.elements[i])
                return false;

        return true;
    }
    bool operator!=(farray cref other) const { return !(*this == other); }
};

/** Array of natural numbers. */
using dim = farray<nat>;
/** Array of integers */
using idim = farray<int>;
/** Array of scalars. */
using vec = farray<num>;

#define arr_result(size_source) val size{size_source}; farray<T> result(size); forsize result[i] =
#define transformer template <typename T> farray<T>
#define reducer template <typename T> T
#define arg farray<T> cref
#define transform_op transformer operator
#define inplace_op transformer cref operator

/* Helper functions */

/** Forms dimension sizes from a dimensions */
dim dimensions_sizes(dim cref dimensions);

/* Selection and iteration functions */

/** Selects elements from array. */
transformer select(arg array, nat step = 1, nat offset = 0) {
    arr_result((array.size - offset) / step) array[i * step + offset];
    return result;
}
/** Selects elements from array. */
transformer reverse(arg array) {
    arr_result(array.size) array[size - i - 1];
    return result;
}
/** Selects elements in collections at indices. */
transformer select_at(arg source, idim cref indices) {
    arr_result(indices.size) source[indices[i]];
    return result;
}
/** Selects elements in collections at indices. */
transformer select_at(arg source, dim cref indices) {
    arr_result(indices.size) source[indices[i]];
    return result;
}
/** Concatenates two arrays. */
transformer concat(farray<T> a, farray<T> b) {
    var size{a.size + b.size};
    farray<T> result(size);

    var i{0u};
    for (cval a1 : a)
        result[i++] = a1;
    for (cval b1 : b)
        result[i++] = b1;

    return result;
}
/** Returns a portion of an array. */
transformer slice(arg source, int start = 0, int count = -1) {
    val size{source.size};
    val _start = to_nat(start >= 0 ? start : to_int(size) + start);

    check(_start <= size, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start)

    if (count < 0)
        return farray<T>(source.elements + start, size - start);

    return farray<T>(source.elements + _start, count);
}
/** Flattens collections of arrays into a single one through concatenation. */
transformer flatten(farray<farray<T>> arrays) {
    var size{0u};
    for (cval array : arrays)
        size += array.size;

    farray<T> result(size);

    var i{0u};
    for (cval array : arrays)
        for (cval element : array)
            result.elements[i++] = element;

    return result;
}

// todo: unselect, requires base algorithms...
///** Selects elements from collections except elements at specified indices. */
//template<typename T>
//farray<T> unselect(farray<T> source, dim cref ind) {
//    // todo: unique
//    // todo: sort
//    // ...
//
//    val size = source.size;
//    val ind_size{ind.size};
//
//    if (size == ind_size) return {};
//
//    check(size >= ind_size, "Source size was smaller then selected indices size. " + size + " < " + ind_size + ".")
//    farray<T> dest;
//    dest.reserve(size - ind_size);
//
//    for (var i{0u}; i < size; ++i)
//        if (!contains<nat>(ind, i))
//            dest.push_back(source[i]);
//
//    return dest;
//}
/* Operators */

transform_op-(arg arr) {
    arr_result(arr.size) -arr[i];
    return result;
}

transform_op+(arg arr, T cref scalar) {
    arr_result(arr.size) arr[i] + scalar;
    return result;
}
transform_op-(arg arr, T cref scalar) { return arr + -scalar; }

transform_op+(arg a, arg b) {
    arr_result(a.size) a[i] + b[i];
    return result;
}
transform_op-(arg a, arg b) {
    arr_result(a.size) a[i] - b[i];
    return result;
}

transform_op*(arg a, arg b) {
    arr_result(a.size) a[i] * b[i];
    return result;
}
transform_op/(arg a, arg b) {
    arr_result(a.size) a[i] / b[i];
    return result;
}

transform_op*(arg a, T cref b) {
    arr_result(a.size) a[i] * b;
    return result;
}
transform_op*(T cref a, arg b) { return b * a; }

transform_op/(arg a, T cref b) {
    arr_result(a.size) a[i] / b;
    return result;
}

/* In-place */

inplace_op+=(arg a, T cref b) {
    forin(a.size) a[i] += b;
    return a;
}
inplace_op-=(arg a, T cref b) {
    forin(a.size) a[i] -= b;
    return a;
}
inplace_op*=(arg a, T cref b) {
    forin(a.size) a[i] *= b;
    return a;
}
inplace_op/=(arg a, T cref b) {
    forin(a.size) a[i] /= b;
    return a;
}

inplace_op+=(arg a, arg b) {
    forin(a.size) a[i] += b[i];
    return a;
}
inplace_op-=(arg a, arg b) {
    forin(a.size) a[i] -= b[i];
    return a;
}
inplace_op*=(arg a, arg b) {
    forin(a.size) a[i] *= b[i];
    return a;
}
inplace_op/=(arg a, arg b) {
    forin(a.size) a[i] /= b[i];
    return a;
}

/* Reducers */
/** Multiplies together all elements of an array. */
reducer product(arg data) {
    T res{1};
    for (const auto &d : data)
        res *= d;
    return res;
}
/** Sums together all elements of an array. */
reducer sum(arg data) {
    T res{0};
    for (const auto &d : data)
        res += d;
    return res;
}
/** Dot product for two vectors. Takes a sum from hadamard product of a and b. */
reducer dot(arg a, arg b) {
    return sum(a * b);
}

/* Transformers */
/** Extends each element of first array with each element of a second. */
transformer extend(arg a, arg b) {
    val size{a.size * b.size};
    vec result(size);

    var i{0u};
    for (cval a1 : a)
        for (cval b1 : b)
            result[i++] = a1 * b1;

    return result;
}

template<typename T>
void swap(farray<T> ref arr, int i1, int i2) {
    val size{arr.size};

    if (i1 < 0) i1 += size;
    if (i2 < 0) i2 += size;

    T v {std::move(arr.elements[i1])};
    arr[i1] = arr[i2];
    arr[i2] = std::move(v);
}

/** Splits an array into two parts. */
template<typename T>
std::tuple<farray<T>, farray<T>> split(farray<T> arr, nat split_index) {
    val s2{arr.size - split_index};

    farray<T> a1(split_index);
    farray<T> a2(s2);

    var size{split_index};
    forsize a1[i] = arr[i];

    size = s2;
    forsize a1[i] = arr[split_index + i];

    return {a1, a2};
}

/** Splits an array at given indices. */
template<typename T>
farray<farray<T>> split(farray<T> array, dim cref split_indices) {
    farray<farray<T>> results(array.size);
    var start{0u};

    var j{0u};
    for (cval end : split_indices) {
        for (var i{start}; i < end; ++i) {
            results[j][i - start] = array[i];
        }
        j++;
    }

    return results;
}

/** Removes range of elements from collections. Returns a copy. */
transformer splice(farray<T> source, int start, int count = 1) {
    val size = source.size;
    val _start = to_nat(start >= 0 ? start : to_int(size) + start);

    check(_start < size, "Start index should be in range: [-" + size + ", " + size + "). Received: " + start)

    if (count < 0)
        return farray<T>(source.begin(), source.begin() + _start);

    val _count = to_nat(count);
    val _end{_start + _count};

    check(_end <= size, "Splice end's index was out of bounds. " + _start + " + " + _count + " = " + _end + " > " + size + ".")

    farray<T> result(size - _count);

    for (var i = 0u; i < _start; ++i)
        result[i] = source[i];

    for (var i = _end; i < size; ++i)
        result[i - _count] = source[i];

    return result;
}

#undef arr_result
#undef transformer
#undef reducer
#undef arg
#undef transform_op
#undef inplace_op

#endif //MACHINE_LEARNING_ARRAYS_H
