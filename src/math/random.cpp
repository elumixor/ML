//
// Created by vlado on 3/2/20.
//

#include <random>
#include "math/random.h"

std::random_device device;
std::default_random_engine engine(device());

scalar random_uniform(scalar min, scalar max) {
    static std::uniform_real_distribution<scalar> distribution(min, max);
    return distribution(engine);
}
scalar random_normal(scalar mean, scalar std) {
    static std::normal_distribution<scalar> distribution(mean, std);
    return distribution(engine);
}

//vec random_uniform(nat size, scalar min, scalar max) {
//    vec result(size);
//
//    for (var i{0u}; i < size; ++i)
//        result[i] = random_uniform(min, max);
//
//    return result;
//}
//vec random_normal(nat size, scalar mean, scalar std) {
//    vec result(size);
//
//    for (var i{0u}; i < size; ++i)
//        result[i] = random_normal(mean, std);
//
//    return result;
//}
