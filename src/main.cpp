//
// Created by vlado on 2/2/20.
//

#include <declarations.h>
#include <arrays/arrays.h>
#include <output/to_string.h>
#include <arrays/iterators.h>
#include <math/tensor.h>
#include <math/matht.h>
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

//    print(dot(vec{1, 2, 3}, vec{1, 0, 1}));

    // Printing tensor in different views
//    print(Y);
//    print_line();
//    print(Y.view({2, 0, 1}));
//    print_line();
//    print(Y.flat({2, 0, 1}));
//    print_line();

    print(Y);
    print_line();
    print(Y.flat());
    print_line();
    print(Y.view({2, 1, 0}));
    print_line();
    print(Y.view({2, 1, 0}).flat());
//    dim dims{3, 2, 4};
//    composite_index a(dims);


//    for (cval index : a) {
//        print(index + " " + composite_index(dims, index).unwrapped());
//    }

    // Tensor properties
//    print(sum(Y));
//    print(mean(Y));
}
