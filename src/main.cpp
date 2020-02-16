//
// Created by vlado on 2/2/20.
//

#include <common/declarations.h>
#include <collections/arrays.h>
#include <output/to_string.h>
#include <collections/tensor.h>
#include <utility>
#include <output/printable.h>


int main() {
    tensor Y{{
                     {0, 1, 2},
                     {3, 4,  5}
             },
             {
                     {6, 7, 8},
                     {9, 10, 11}
             }};

    tensor in{1, 2, 3};
    tensor W{{2, 2, 2},
             {1, 0, 1},
             {0, 3, 0}};

    tensor batch{{1, 0, 1},
                 {1, 0, 1},
                 {2, 2, 2}};


//    print(in);
//    print(W);
//    print(dot(W, in));
//    print(dot({1, 2, 3}, {2, 2, 2}));
//    print(dot({1, 2, 3}, {1, 0, 1}));
//    print(dot({1, 2, 3}, {0, 3, 0}));
    print(dot(W, batch));
//    print(dot(W, batch, {{0}, {0}}));
//    print(extend(Y, {1, 2, 3}));
//    print(extend(tensor{1, 2, 3}, tensor{1, 0, 2}));
//    print(Y);
//    print(flatten<nat>({{1,2,3}, {1,2,3}}));

}
