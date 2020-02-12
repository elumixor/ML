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

int main() {
//    print( (dim{1,2,3}) - (dim{2,3,4}));

    tensor Y{{
                     {1, 1, 1},
                     {1, 0, 0}
             },
             {       {1, 0, 0},
                     {1, 0, 1}
             }};


    dim a{1, 2, 3};
    dim b{a};

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
