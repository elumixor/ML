//
// Created by vlado on 2/2/20.
//

#include "declarations.h"
#include "output/printable.h"
#include <iostream>
#include <utility>

printable printable::empty{};
printable printable::new_line{"\n"};

printable::printable(const char *arg) : str{string(arg)} {}
printable::printable(string str) : str{std::move(str)} {}
printable::printable(const char &c) : str{string(1, c)} {}

printable &printable::operator=(const string &x) {
    str = x;
    return *this;
}

void printable::__print() const {
    std::cout << str << std::endl;
}

printable operator+(const printable &a, const printable &b) {
    return printable(a.str + b.str);
}

printable::operator string() const { return str; }

printable operator ""_pr(const char *str, size_t) {
    return printable(str);
}
