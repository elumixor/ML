//
// Created by vlado on 2/2/20.
//
//
//#include <nn/network.h>
//#include <output/printable.h>
//#include <math/matht.h>
//#include <iostream>
//#include <vec.h>
//#include <variant>
//#include <output/to_string.h>
#include <declarations.h>
#include <arrays/farray.h>
#include <output/to_string.h>
#include <arrays/indices.h>
//#include <math/dim.h>
//#include <math/vec.h>

//void p(dim cref d) {
//    printf("f");
//}
template<typename T>

void p1(farray<T> cref d) {
    printf("f?");
}

int main() {
    dim a{1, 2, 3};

    print(a);
    for (var elem: a)
        print(elem);

    for (cval ind : indices(a))
        print(ind);

    //    tensor Y{{1, 1, 1},
//             {1, 0, 0},
//             {1, 0, 1}};
//
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
