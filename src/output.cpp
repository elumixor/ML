//
// Created by vlado on 2/2/20.
//

#include <iostream>
#include <utility>
#include "../include/def.h"
#include "../include/printable.h"


printable::printable(const char *arg) : str{string(arg)} {}
void printable::__print() const {
    std::cout << str << std::endl;
}
printable::printable(string str) : str{std::move(str)} {}
printable operator+(const printable &a, const printable &b) {
    return printable(a.str + b.str);
}
