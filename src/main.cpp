//
// Created by vlado on 2/2/20.
//

#include <functional.h>
#include <iterable.h>
#include "../include/tensor.h"

int main() {
    print(tensor({3, 4}, 3));
    print(tensor::random({3, 4, 2}) + '\n');
    print(tensor::random_normal({3, 4, 2}));
}
