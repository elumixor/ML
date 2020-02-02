//
// Created by vlado on 2/2/20.
//

#include "../include/tensor.h"
#include "../include/output.h"

int main() {
    tensor a({3, 1, 1, 3, 4, 5});
    tensor b{{{1, 2, 3}, {2, 2, 3}},
             {{1, 1, 1}, {3, 1, 1}}};

    print(a);
    print("b: " + b);
}