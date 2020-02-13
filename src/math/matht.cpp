////
//// Created by vlado on 2/2/20.
////
//
//#include "math/matht.h"
//#include <math/tensor.h>
//#include <iterable.h>
//#include <exceptions.h>
//
//scalar sum(tensor cref t) { return sum(t.elements); }
//tensor sum(tensor cref t, nat dim) { nimpl }
//scalar mean(tensor cref t) { return sum(t) / t.size(); }
//tensor outer(tensor cref a, tensor cref b) {
//    var asz = a.size();
//    var bsz = b.size();
//
//    vec elements(asz * bsz);
//
//    var j{0u};
//    for (var i{0u}; i < asz; ++i)
//        for (var k{0u}; k < bsz; ++k)
//            elements[j++] = a.elements[i] * b.elements[k];
//
//    return tensor(concat(a.dimensions, b.dimensions), elements);
//}
//tensor dot(tensor cref a, tensor cref b, nat dim_a, nat dim_b) {
//    check(dim_a < a.rank, "Dimension index for first tensor exceeds its rank. " + dim_a + " >= " + a.rank + ".");
//    check(dim_b < b.rank, "Dimension index for second tensor exceeds its rank. " + dim_b + " >= " + b.rank + ".");
//
//    val size_a{a.dimensions[dim_a]};
//    val size_b{b.dimensions[dim_b]};
//
//    check(size_a == size_b, "Tensors dimensions in dot product were not equal.\n\t" + a.dimensions + " and " + b.dimensions + " on "
//                            + dim_a + " (" + a.dimensions[dim_a] + ") and " + dim_b + " (" + b.dimensions[dim_b] + ").");
//
//    // Dimensions of the resulting tensor
//    val dims{concat(unselect(a.dimensions, {dim_a}),
//                    unselect(b.dimensions, {dim_b}))};
//
//    val split_index = a.dimensions.size() - 1;
//
//    tensor result(dims, 0);
//
//    for (cval ind : indices(dims)) {
//        val[ind_a, ind_b] = split(ind, split_index); // split resulting index into corresponding source index
//        result[concat(ind_a, ind_b)] = a.vec(dim_a, ind_a) * b.vec(dim_b, ind_b);
//    }
//
//    return result;
//}
//tensor dot(tensor cref a, tensor cref b, cvnat dim_a, cvnat dim_b) {
//    // dim_a is an array of dimensions indices, where we treat a tensor as covectors
//    // dim_b is an array of dimensions indices where we treat b tensor as vectors
//
//
//
//    return tensor();
//}
