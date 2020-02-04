//
// Created by vlado on 2/2/20.
//

#include "math/matht.h"
#include <math/tensor.h>

num sum(const tensor &t) { return sum(t.elements); }
num mean(const tensor &t) { return sum(t) / t.size(); }