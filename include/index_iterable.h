//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#ifndef MACHINE_LEARNING_INDEX_ITERABLE_H
#define MACHINE_LEARNING_INDEX_ITERABLE_H

#include <declarations.h>

/* Indices iterable */
declare(__indices_iterable) {
    vnat dimensions;

    explicit __indices_iterable(vnat dimensions);

    /* Iterator  */
    declare(__indices_iterator) {
        cvnat dimensions;
        vnat indices;

        explicit __indices_iterator(cvnat dimensions);
        __indices_iterator(cvnat dimensions, vnat indices);

        cvnat operator*() const;
        const __indices_iterator &operator++();
        bool operator!=(c__indices_iterator) const;
    };

    [[nodiscard]] __indices_iterator begin() const;
    [[nodiscard]] __indices_iterator end() const;

};

/* Iterator yielding methods */
inline __indices_iterable indices(cvnat dimensions) { return __indices_iterable(dimensions); }


#endif //MACHINE_LEARNING_INDEX_ITERABLE_H
