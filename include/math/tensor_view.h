//
// Created by Vladyslav Yazykov on 12/02/2020.
//

#ifndef MACHINE_LEARNING_TENSOR_VIEW_H
#define MACHINE_LEARNING_TENSOR_VIEW_H

#include <declarations.h>
#include <arrays/iterators.h>

struct tensor;
struct flat_view;

/** Tensor view iterates on elements of a tensor, with respect to dimensions. */
struct tensor_view {
    struct iterator {
        const scalar *data_start;

        dim dimensions;
        dim dimension_sizes;

        const nat step;
        const nat dimension_index;

        iterator(const scalar *data_start, dim dimensions, dim dimension_sizes, nat step, nat dimension_index);
        inline explicit iterator(const scalar *data) : data_start{data}, step{0}, dimension_index{0} {}

        tensor_view operator*() const;
        iterator cref operator++();
        bool operator!=(iterator cref other) const;
    };

    /** Elements starting pointer */
    const scalar *data_start;

    /** Dimensions array reference. (How many components does each dimension have). */
    const dim dimensions;
    /** Dimensions sizes. (How many elements does each dimension contain).*/
    const dim dimension_sizes;

    /** Points to the current dimension */
    const nat dimension_index;

    /* Helper methods*/
    /** Dimension size: specifies number of selected elements in this dimension. */
    [[nodiscard]] inline nat count() const { return dimensions[dimension_index]; }
    /** Step: distance between adjacent elements along this dimension. */
    [[nodiscard]] inline nat step() const { return dimension_sizes[dimension_index]; }
    /** Pointer to data end. */
    [[nodiscard]] inline const scalar *data_end() const { return data_start + count() * step(); }
    [[nodiscard]] inline nat size() const { return dimensions[0] * dimension_sizes[0]; }
    /* Methods */
    /** True if dimension index is one before the last. */
    [[nodiscard]] inline bool is_vector() const { return dimension_sizes.size - dimension_index < 2; }
    /** Returns select view of vector elements */
    [[nodiscard]] inline select<scalar> vector() const { return select(data_start, step(), count()); }
    /** Accesses subview at index. */
    [[nodiscard]] inline tensor_view operator[](nat index) const {
        return tensor_view(data_start + step() * index, dimensions, dimension_sizes, dimension_index);
    }
    /** Returns a view with elements flattened to a single array. */
    [[nodiscard]] flat_view flat() const;

    /* Iterator methods */
    [[nodiscard]] inline iterator begin() const { return iterator(data_start, dimensions, dimension_sizes, step(), dimension_index); }
    [[nodiscard]] inline iterator end() const { return iterator(data_end()); };

    /** Implicit constructor of a view from a tensor. */
    tensor_view(tensor cref);
    tensor_view(tensor cref, dim cref);
    tensor_view(vec cref start, dim dimensions, dim dimension_sizes);
    tensor_view(const scalar *data_start, dim dimensions, dim dimension_sizes, nat dimensions_index);
};


#endif //MACHINE_LEARNING_TENSOR_VIEW_H
