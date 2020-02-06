//
// Created by vlado on 2/2/20.
//

#include "math/matht.h"
#include <math/tensor.h>
#include <iterable.h>

num sum(ctensor t) { return sum(t.elements); }
num mean(ctensor t) { return sum(t) / t.size(); }
tensor outer(ctensor a, ctensor b) {
    var asz = a.size();
    var bsz = b.size();

    vec elements(asz * bsz);

    var j{0u};
    for (var i{0u}; i < asz; ++i)
        for (var k{0u}; k < bsz; ++k)
            elements[j++] = a.elements[i] * b.elements[k];

    return tensor({1}, elements);
}
tensor dot(ctensor a, ctensor b, nat dim_a, nat dim_b) {
    val size_a{a.dimensions[dim_a]};
    val size_b{a.dimensions[dim_b]};

    check(size_a == size_b, "Tensors dimensions in dot product were not equal. " + a.dimensions + " and " + b.dimensions + " on "
                            + dim_a + " (" + a.dimensions[dim_a] + ") and (" + b.dimensions[dim_b] + ").");

    // Copy dimensions
    var j{0u};
    vnat d_a{unselect(a.dimensions, {dim_a})};
    vnat d_b{unselect(b.dimensions, {dim_a})};

    vnat dims(concat(d_a, d_b));

    print(indices(d_a));
    print(indices(d_b));

    // for all other dimensions
    tensor result(dims, 0);

//    for (cval dim_indices : dims) {
        // go through all subdimensions of a and b
//        for (var k{0u}; k < size_a; ++k)
//            result[dim_indices] += sum(a.subdim(dim_a, k) * b.subdim(dim_b, k), dim=???);
//    }

    return result;
}
