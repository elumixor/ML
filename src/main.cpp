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

    val dims = vnat{3, 4, 2};
    num sum{0};

    val count{10000u};
    for (var i{0u}; i < count; ++i) {
        val t{tensor::random(dims)};
        var m{mean(t)};
        sum += m;
        print("Mean:\t" + m + ".\tApproximation: " + sum / i);
    }

    print("Final approximation: " + sum / count);
}
