//
// Created by Vladyslav Yazykov on 12/02/2020.
//


#include <arrays/arrays.h>
#include <math/tensor_view.h>

tensor_view::tensor_view(vec cref start, dim dimensions, dim dimension_sizes)
        : data_start{start.elements}, move_init_s(dimensions), move_init_s(dimension_sizes), dimension_index{0} {}

tensor_view::tensor_view(const scalar *data_start, dim dimensions, dim dimension_sizes, nat dimension_index)
        : copy_init_s(data_start), move_init_s(dimensions), move_init_s(dimension_sizes), copy_init_s(dimension_index) {}

tensor_view::iterator::iterator(const scalar *data_start, dim dimensions, dim dimension_sizes, nat step, nat dimension_index)
        : copy_init_s(data_start), move_init_s(dimensions), move_init_s(dimension_sizes), copy_init_s(step), copy_init_s(dimension_index) {}

bool tensor_view::iterator::operator!=(tensor_view::iterator cref other) const { return data_start != other.data_start; }
const tensor_view::iterator ref tensor_view::iterator::operator++() {
    data_start += step;
    return *this;
}

tensor_view tensor_view::iterator::operator*() const {
    return tensor_view(data_start, dimensions, dimension_sizes, dimension_index + 1);
}
