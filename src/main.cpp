//
// Created by vlado on 2/2/20.
//

#include "../include/tensor.h"

int main() {

//    tensor a({3, 1, 1, 3, 4, 5});
//    num x{a}; // throws

//    print(a);
//    print_line();

    tensor b{{{1, 2, 3}, {2, 2, 3}},
             {{1, 1, 1}, {3, 1, 1}}};


    print(b[0] + "\n");
    print(b[0][0] + "\n");
    print(b[0][5][0] + "\n");

//    print(a[0]);
//    print_line();
//
//    print(a[1]);
//    print_line();
//
//    print(a.reshaped({3, 2}));
//    print_line();
//
//    print("b: " + b);
}