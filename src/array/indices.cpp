//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#include <arrays/iterators.h>
#include <math/matht.h>

void move_forward(dim cref maximum, dim ref current) {
    var dim{maximum.size - 1};
    while (dim > 0 && current[dim] >= maximum[dim] - 1)
        current[dim--] = 0;

    current[dim]++;
}

// Iterator moving forward
composite_index::iterator cref composite_index::iterator::operator++() {
    move_forward(maximum, current);
    return *this;
}

// Indices methods
dim composite_index::operator[](nat index) const {
    dim result(dimensions.size);
    var size{dimensions.size};

    forsize {
        var ds{sizes[i]};
        nat d = index / ds;
        result.elements[i] = d;
        index -= ds * d;
    };

    return result;
}
composite_index ref composite_index::operator++() {
    move_forward(dimensions, current_index);
    return *this;
}
nat composite_index::flat() const {
    return form_index(current_index, sizes);
}
nat composite_index::flat(dim cref dimension_sizes) const {
    return dot(current_index, dimension_sizes);
}
nat composite_index::form_index(dim cref index, dim cref sizes) {
    return dot(index, sizes);
}