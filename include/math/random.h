//
// Created by vlado on 3/2/20.
//

#ifndef CALCULUS_RANDOM_H
#define CALCULUS_RANDOM_H

#include <declarations.h>
#include <arrays/arr.h>

scalar random_uniform(scalar min = 0, scalar max = 1);
scalar random_normal(scalar mean = .5, scalar std = .5);

/* Random vectors */
/**
 * Creates a vector with uniformly distributed random components.
 * @param size Vector size
 */
vec random_uniform(nat size, scalar min = 0, scalar max = 1);
/**
 * Creates a vector with normally distributed random components numbers.
 * @param size Vector size
 * @param min Distribution mean
 * @param max Distribution standard deviation
 */
vec random_normal(nat size, scalar mean = .5, scalar std = .5);
#endif //CALCULUS_RANDOM_H
