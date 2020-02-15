//
// Created by vlado on 3/2/20.
//

#ifndef CALCULUS_RANDOM_H
#define CALCULUS_RANDOM_H

#include <declarations.h>
#include <arrays/arrays.h>

num random_uniform(num min = 0, num max = 1);
num random_normal(num mean = .5, num std = .5);

/* Random vectors */
/**
 * Creates a vector_view with uniformly distributed random components.
 * @param size Vector size
 */
vec random_uniform(nat size, num min = 0, num max = 1);
/**
 * Creates a vector_view with normally distributed random components numbers.
 * @param size Vector size
 * @param min Distribution mean
 * @param max Distribution standard deviation
 */
vec random_normal(nat size, num mean = .5, num std = .5);
#endif //CALCULUS_RANDOM_H
