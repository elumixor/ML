//
// Created by vlado on 2/2/20.
//

#include "math/matht.h"
#include <math/tensor.h>

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
