//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#ifndef MACHINE_LEARNING_INDICES_H
#define MACHINE_LEARNING_INDICES_H

#include <arrays/farray.h>

/* Indices iterable. Takes a dim (array of natural numbers) */
struct indices {
    dim dimensions;

    explicit inline indices(dim dimensions) : move_init_s(dimensions) {}

    /* Iterator  */
    struct iterator {
        dim cref maximum;
        dim current;

        explicit iterator(dim cref maximum);
        iterator(dim cref maximum, dim current);

        dim cref operator*() const;
        const iterator &operator++();
        bool operator!=(iterator cref) const;
    };

    [[nodiscard]] iterator begin() const;
    [[nodiscard]] iterator end() const;
};


#endif //MACHINE_LEARNING_INDICES_H
