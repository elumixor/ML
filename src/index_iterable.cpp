//
// Created by Vladyslav Yazykov on 06/02/2020.
//

#include <index_iterable.h>


using int_itb = __indices_iterable;
using int_itr = __indices_iterable::__indices_iterator;

/* Indices iterable */
// Iterable constructor
__indices_iterable::__indices_iterable(vnat dimensions) : move_init_s(dimensions) {}
// Constructor
int_itb::__indices_iterator::__indices_iterator(cvnat dimensions) : copy_init_s(dimensions), indices(this->dimensions.size()) {}
int_itb::__indices_iterator::__indices_iterator(cvnat dimensions, vnat indices) : copy_init_s(dimensions), move_init_s(indices) {}
// Yielding value
cvnat int_itr::operator*() const { return indices; }
// Moving forward
const int_itr &int_itr::operator++() {
    var dim{dimensions.size() - 1};
    while (dim > 0 && indices[dim] >= dimensions[dim] - 1)
        indices[dim--] = 0;

    indices[dim] += 1;
    return *this;
}
bool int_itr::operator!=(c__indices_iterator other) const { return indices != other.indices; }
// Begin, End
int_itr int_itb::begin() const { return int_itr(dimensions); }
int_itr int_itb::end() const {
    vnat res(dimensions.size());
    res[0] = dimensions[0];
    return int_itr(dimensions, res);
}
