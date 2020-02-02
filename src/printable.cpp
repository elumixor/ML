//
// Created by vlado on 2/2/20.
//

#include <iostream>
#include <utility>
#include "../include/def.h"
#include "../include/printable.h"

printable printable::empty{};
printable::printable(const char *arg) : str{string(arg)} {}
void printable::__print() const {
    std::cout << str << std::endl;
}
printable::printable(string str) : str{std::move(str)} {}
printable &printable::operator=(const string &x) {
    str = x;
    return *this;
}
printable::operator string() const { return str; }
printable operator+(const printable &a, const printable &b) {
    return printable(a.str + b.str);
}
printable operator ""_pr(const char *str, size_t) {
    return printable(str);
}
