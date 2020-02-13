//
// Created by Vladyslav Yazykov on 12/02/2020.
//

#ifndef MACHINE_LEARNING_TENSOR_VIEW_H
#define MACHINE_LEARNING_TENSOR_VIEW_H

#include <declarations.h>
#include <arrays/iterators.h>

struct tensor;

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

//    struct vector_view {
//        struct iterator {
//            const scalar *data;
//            const nat step{0};
//
//            inline iterator(const scalar *data, const nat step) : data{data}, step{step} {}
//            inline explicit iterator(const scalar *data) : data{data} {}
//
//            inline bool operator!=(iterator cref other) const { return data != other.data; }
//            inline iterator cref operator++() {
//                data += step;
//                return *this;
//            }
//            inline scalar cref operator*() { return *data; }
//        };
//
//        const scalar *start;
//        const nat step;
//        const nat count;
//
//        vector_view(const scalar *start, const nat step, const nat count) : start(start), step(step), count(count) {}
//
//        [[nodiscard]] inline iterator begin() const { return iterator(start, step); }
//        [[nodiscard]] inline iterator end() const { return iterator(start + step * count); };
//    };

    /** Elements starting pointer */
    const scalar *data_start;

    /** Dimensions array reference */
    const dim dimensions;
    /** Dimensions sizes */
    const dim dimension_sizes;

    /** Points to the current dimension */
    const nat dimension_index;

    /** Dimension size: specifies number of selected elements in this dimension. */
    [[nodiscard]] inline nat count() const { return dimensions[dimension_index]; }
    /** Step: distance between adjacent elements along this dimension. */
    [[nodiscard]] inline nat step() const { return dimension_sizes[dimension_index]; }
    /** Pointer to data end. */
    [[nodiscard]] inline const scalar *data_end() const { return data_start + count() * step(); }

    [[nodiscard]] inline bool is_vector() const { return dimension_sizes.size - dimension_index < 2; }
    [[nodiscard]] inline select<scalar> vector() const { return select(data_start, step(), count()); }
//    [[nodiscard]] inline vec::iterator vector_view() const { return vec(data_start, step(), count()); }

    [[nodiscard]] inline iterator begin() const { return iterator(data_start, dimensions, dimension_sizes, step(), dimension_index); }
    [[nodiscard]] inline iterator end() const { return iterator(data_end()); };

    tensor_view(vec cref start, dim dimensions, dim dimension_sizes);
    tensor_view(const scalar *data_start, dim dimensions, dim dimension_sizes, nat dimensions_index);
};

#endif //MACHINE_LEARNING_TENSOR_VIEW_H
