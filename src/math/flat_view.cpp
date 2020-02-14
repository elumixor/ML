//
// Created by Vladyslav Yazykov on 14/02/2020.
//

#include <flat_view.h>
#include <output/to_string.h>


flat_view::iterator ref flat_view::iterator::operator++() {
    ++index;
    return *this;
}
scalar cref flat_view::iterator::operator*() const { return *(data + index.unwrapped(dim_sizes)); }
scalar cref flat_view::operator[](nat index) const {
    return data[composite_index::form_index(index, dim_elements)];
}
flat_view::iterator flat_view::begin() const {
    return flat_view::iterator(data, dim_components, dim_elements);
}
flat_view::iterator flat_view::end() const {
    dim d(dim_components.size, 0);
    d[0] = dim_components[0];
    return flat_view::iterator(dim_elements, composite_index(d, d));
}
flat_view::flat_view(const scalar *data, dim dim_components, dim dim_elements)
        : cinits(data), minits(dim_components), minits(dim_elements) {}
