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

    print(splice(a, 1));
    print(splice(a, 1, 2));
    print(splice(a, 1, 3));
//    print(splice(a, 1, 4));
    print(splice(a, -2, -1));
}