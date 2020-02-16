//
// Created by Vladyslav Yazykov on 16/02/2020.
//

#ifndef MACHINE_LEARNING_PAIR_H
#define MACHINE_LEARNING_PAIR_H

template<typename T, typename U>
struct pair {
    T first;
    U second;

    pair(T first, U second) : first{first}, second{second} {}

    pair(pair cref other) : cinit(first, other), cinit(second, other) {}
    pair(pair mref other) noexcept : minit(first, other), minit(second, other) {}
};

#endif //MACHINE_LEARNING_PAIR_H
