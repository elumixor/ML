//
// Created by Vladyslav Yazykov on 15/02/2020.
//

#ifndef MACHINE_LEARNING_COMPOSITE_INDEX_H
#define MACHINE_LEARNING_COMPOSITE_INDEX_H

#include <collections/arrays.h>

/* Indices iterable. Takes a dim (collections of nat numbers) */
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

    [[nodiscard]] nat flat() const;
    [[nodiscard]] nat flat(dim cref dimension_sizes) const;
    dim operator[](nat i) const;
    composite_index ref operator++();
    [[nodiscard]] nat size() const { return product(dimensions); }

    [[nodiscard]] inline iterator begin() const { return iterator(dimensions, current_index); }
    [[nodiscard]] inline iterator end() const {
        dim d(dimensions.size, 0);
        d[0] = dimensions[0] + 1;
        return iterator(dimensions, d);
    }

    static nat form_index(dim cref index, dim cref sizes);
};

#endif //MACHINE_LEARNING_COMPOSITE_INDEX_H
