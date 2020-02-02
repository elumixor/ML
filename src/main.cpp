//
// Created by vlado on 2/2/20.
//

#include "../include/def.h"

int main() {
    print(tensor({3, 1, 1, 3, 4, 5}, {3,2}));
    print(tensor(1, {3,2}));
//    print(tensor({3, 1, 3, 4, 5}, {3,2})); // will throw

    print(" times ");
    print((1.0 + 1.f) + 3.f + " dsa" + " times " + "hello" + " from ML");
}