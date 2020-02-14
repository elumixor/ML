//
// Created by Vladyslav Yazykov on 12/02/2020.
//


#include <arrays/arrays.h>
#include <tensor_view.h>
#include <tensor.h>
#include <math/flat_view.h>

tensor_view::tensor_view(vec cref start, dim dimensions, dim dimension_sizes)
        : data_start{start.elements}, minits(dimensions), minits(dimension_sizes), dimension_index{0} {}

tensor_view::tensor_view(const scalar *data_start, dim dimensions, dim dimension_sizes, nat dimension_index)
        : cinits(data_start), minits(dimensions), minits(dimension_sizes), cinits(dimension_index) {}

tensor_view::tensor_view(tensor cref t) : tensor_view(t.elements, t.dimensions, dimensions_sizes(t.dimensions)) {}
tensor_view::tensor_view(tensor cref t, dim cref dimension_indices)
        : tensor_view(t.elements, select_at(t.dimensions, dimension_indices),
                      select_at(dimensions_sizes(t.dimensions), dimension_indices)) {}
tensor_view::iterator::iterator(const scalar *data_start, dim dimensions, dim dimension_sizes, nat step, nat dimension_index)
        : cinits(data_start), minits(dimensions), minits(dimension_sizes), cinits(step), cinits(dimension_index) {}

bool tensor_view::iterator::operator!=(tensor_view::iterator cref other) const { return data_start != other.data_start; }

const tensor_view::iterator ref tensor_view::iterator::operator++() {
    data_start += step;
    return *this;
}
tensor_view tensor_view::iterator::operator*() const {
    return tensor_view(data_start, dimensions, dimension_sizes, dimension_index + 1);
}

flat_view tensor_view::flat() const {
    return flat_view(data_start, dimensions, dimension_sizes);
}
