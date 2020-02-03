//
// Created by vlado on 2/2/20.
//

#include <functional.h>
#include <iterable.h>
#include "../include/tensor.h"

int main() {
    tensor b{
            {{1,  2,  3},  {4,  5,  6}},
            {{7,  8,  9},  {10, 11, 12}},
            {{13, 14, 15}, {16, 17, 18}},
            {{19, 20, 21}, {22, 23, 24}},
    };
//    print(b.subdim(-1, 0, false));
    print(b.subdim(0, -1, false));

    print(b + "\n");
    print(b.subdim(0, 0, false));
    print(b.subdim(0, 1, false));
    print(b.subdim(0, 2, false));
    print(b.subdim(0, 3, false));
    print_line();

    print(b.subdim(1, 0, false));
    print(b.subdim(1, 1, false));
    print_line();

    print(b.subdim(2, 0, false));
    print(b.subdim(2, 1, false));
    print(b.subdim(2, 2, false));
    print_line();
}
