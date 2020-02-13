//
// Created by vlado on 2/2/20.
//
//
#include <declarations.h>
#include <arrays/arrays.h>
#include <output/to_string.h>
#include <arrays/iterators.h>
#include <math/tensor.h>
#include "output/printable.h"


void iterate(tensor_view cref view) {
    if (view.is_vector()) {
        for (cval n : view.vector())
            print(n);
        print_line();
        return;
    }
    for (cval subview : view)
        iterate(subview);
}

int main() {
//    print( (dim{1,2,3}) - (dim{2,3,4}));
//    tensor v1{1, 2, 3};
//    tensor v2{1, 0, 1};
//
//    for (cval item : v1.elements)
//        print(item);
//    print_line();
//
//    for (cval item : v2.elements)
//        print(item);
//    print_line();
//
//    tensor y1{v1, v2};
//    for (cval item : y1.elements)
//        print(item);
//    print_line();
//
    tensor Y{{
                     {0, 1, 2},
                     {3, 4,  5}
             },
             {
                     {6, 7, 8},
                     {9, 10, 11}
             }};
//
//    for (cval range : Y.dimensions)
//        print(range);
//
//    print_line();
//    print(Y);
//    iterate(Y.view());
//    iterate(Y.view({2, 0, 1}));
//

    val range{vec::range(10, 1, 2)};
    for (cval item : range)
        print(item);
    print_line();

    for (cval item : reverse(range))
        print(item);
    print_line();

    for (cval item : select(range, 2, 2))
        print(item);



//    print_line();
//    dim a{1, 2, 3};
//    dim b{a};

//    tensor W{{1, 2, 0},
//             {3, 4, 0}};
//
//    tensor Y1{{{1, 1, 1}, {2, 2, 1}},
//              {{1, 0, 0}, {3, 5, 0}},
//              {{1, 0, 1}, {4, 5, 1}}};
//
//    tensor W1{{{1, 2, 0}, {0, 1, 3}},
//              {{3, 4, 0}, {1, 0, 3}}};

    // matrix multiplication on batch of multi-dimensional input
//    print(dot(Y, W, 1, 1));
//    print(dot(Y1, W1, 1, 0));
//    print(dot(Y1, W, 1, 0));
//    print(dot({{1,2}, {3,4}}, {{2,3}, {2,1}}, 1, 0));
}
