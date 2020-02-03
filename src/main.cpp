//
// Created by vlado on 2/2/20.
//

#include <functional.h>
#include <iterable.h>
#include "../include/tensor.h"

int main() {
//    tensor b{{{1, 2, 3}, {4,  5,  6}},
//             {{7, 8, 9}, {10, 11, 12}}};
//
//    print(b + "\n");
//    val a = b.subdim(0, 0, false); // fails
//    print(a);
    vec a{1, 2, 3, 4};
    print(a);
    print_line();

//    print(slice(a));// 1 2 3 4
//    print(slice(a, 1));// 2 3 4
//    print(slice(a, 2));// 2 3 4
//    print(slice(a, 3));// 2 3 4
//    print(slice(a, 4));// 2 3 4 // throws

//    print(slice(a, -1));// 4
//    print(slice(a, -2));// 3 4
//    print(slice(a, -4));// 1 2 3 4
//    print(slice(a, -5));// 1 2 3 4 // throws

//    print(splice(a, 1));// 1 3 4
}