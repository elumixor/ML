//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#include <arrays/indices.h>

// Constructor
indices::iterator::iterator(dim cref maximum) : copy_init_s(maximum), current{dim::of(maximum.size, 0)} {}
indices::iterator::iterator(dim cref maximum, dim current) : copy_init_s(maximum), move_init_s(current) {}
// Yielding value
dim cref indices::iterator::operator*() const { return current; }
// Moving forward
const indices::iterator &indices::iterator::operator++() {
    var dim{maximum.size - 1};
    while (dim > 0 && current[dim] >= maximum[dim] - 1)
        current[dim--] = 0;

    current[dim] += 1;
    return *this;
}
bool indices::iterator::operator!=(indices::iterator cref other) const { return current != other.current; }
// Begin, End
indices::iterator indices::begin() const { return indices::iterator(dimensions); }
indices::iterator indices::end() const {
    if (dimensions.empty()) return indices::iterator({}, {});
    val indices = dim::of(dimensions.size, 0);  // indices should be zero everywhere...
    indices[0] = dimensions[0];                         // except for the first dimension
    return indices::iterator(dimensions, indices);
}
