//
// Created by vlado on 3/2/20.
//

#include <math/random.h>
#include "iterable.h"

vec vec_uniform(nat size, num min, num max) {
    vec result(size);

    for (var i{0u}; i < size; ++i)
        result[i] = random_uniform(min, max);

    return result;
}
vec vec_normal(nat size, num mean, num std) {
    vec result(size);

    for (var i{0u}; i < size; ++i)
        result[i] = random_normal(mean, std);

    return result;
}