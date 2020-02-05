//
// Created by vlado on 3/2/20.
//

#include <random>
#include "math/random.h"

std::random_device device;
std::default_random_engine engine(device());

num random_uniform(num min, num max) {
    static std::uniform_real_distribution<num> distribution(min, max);
    return distribution(engine);
}
num random_normal(num mean, num std) {
    static std::normal_distribution<num> distribution(mean, std);
    return distribution(engine);
}
