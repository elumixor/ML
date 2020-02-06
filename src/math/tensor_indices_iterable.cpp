//
// Created by Vladyslav Yazykov on 06/02/2020.
//
#include <math/matht.h>
#include <math/tensor.h>
#include <iterable.h>

using iterable = tensor::indices_iterable;
using iterator = tensor::indices_iterable::indices_iterator;

/* Iterator */
// Constructor
iterable::indices_iterator::indices_iterator(cvnat dimensions) : copy_init_s(dimensions), indices(this->dimensions.size()) {}
iterable::indices_iterator::indices_iterator(cvnat dimensions, vnat indices) : copy_init_s(dimensions), move_init_s(indices) {}
// Yielding value
cvnat iterator::operator*() const { return indices; }
// Moving forward
const iterator &iterator::operator++() {
    var dim{dimensions.size() - 1};
    while (dim > 0 && indices[dim] >= dimensions[dim] - 1)
        indices[dim--] = 0;

    indices[dim] += 1;
    return *this;
}
bool iterator::operator!=(cindices_iterator other) const { return indices != other.indices; }
iterator iterable::begin() const { return iterator(dimensions); }
iterator iterable::end() const {
    vnat res(dimensions.size());
    res[0] = dimensions[0];
    return iterator(dimensions, res);
}

/* Iterable */
tensor::indices_iterable::indices_iterable(vnat dimensions) : move_init_s(dimensions) {}
