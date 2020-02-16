//
// Created by Vladyslav Yazykov on 14/02/2020.
//

#include <collections/arrays.h>

/** Creates an collections of number elements within each dimension. */
dim dimensions_sizes(dim cref dimensions) {
    val size{dimensions.size};
    dim dimension_sizes(size);

    var product{1u};
    for (var i{0u}; i < size; ++i) {
        dimension_sizes[to_int(size) - i - 1] = product;
        product *= dimensions[to_int(size) - i - 1];
    }

    return dimension_sizes;
}