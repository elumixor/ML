//
// Created by vlado on 2/2/20.
//

#include "../include/tensor.h"
#include "../include/output.h"

int main() {
    tensor a({3, 1, 1, 3, 4, 5});
//    tensor b({tensor({tensor{3,1{},1}), tensor({2, 1})});
    tensor b{{1, 2},
             {1, 3}};

//    print(a);
//    print(b.subdim());
    print(b);
//    print((b + a));
//    print((a + b));
//
////    print(tensor({3, 1, 3, 4, 5}, {3,2})); // will throw
//
//    print(" times ");
//    print((1.0 + 1.f) + 3.f + " dsa" + " times " + "hello" + " from ML");
}