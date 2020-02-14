//
// Created by Vladyslav Yazykov on 14/02/2020.
//

#ifndef MACHINE_LEARNING_FLAT_VIEW_H
#define MACHINE_LEARNING_FLAT_VIEW_H

#include <declarations.h>
#include <arrays/iterators.h>
#include <output/to_string.h>

struct flat_view {
    struct iterator {
        const scalar *data{nullptr};
        dim cref dim_sizes;
        composite_index index;

        inline iterator(const scalar *data, dim cref dims, dim cref dim_sizes) : cinits(data), cinits(dim_sizes), index(dims) {}
        inline iterator(dim cref dim_sizes, composite_index index) : cinits(dim_sizes), minits(index) {}

        scalar cref operator*() const;
        inline bool operator!=(iterator cref other) const { return index.current_index != other.index.current_index; }
        iterator ref operator++();
    };

    const scalar *data;

    dim dim_components;
    dim dim_elements;

    flat_view(const scalar *data, dim dim_components, dim dim_elements);

    [[nodiscard]] iterator begin() const;
    [[nodiscard]] iterator end() const;

    /** Accesses element at index */
    scalar cref operator[](nat index) const;
};

#endif //MACHINE_LEARNING_FLAT_VIEW_H
