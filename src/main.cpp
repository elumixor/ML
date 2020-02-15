//
// Created by vlado on 2/2/20.
//

#include <declarations.h>
#include <arrays/arrays.h>
#include <output/to_string.h>
#include <arrays/iterators.h>
#include <math/tensor.h>
#include <math/matht.h>
#include <utility>
#include "output/printable.h"

int main() {
    tensor Y{{
                     {0, 1, 2},
                     {3, 4,  5}
             },
             {
                     {6, 7, 8},
                     {9, 10, 11}
             }};

    print(Y);
    print(Y.view({2, 0, 1}));
    print(Y.view({2, 1, 0}));
}
