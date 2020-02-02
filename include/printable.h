//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_PRINTABLE_H
#define CALCULUS_PRINTABLE_H

struct printable {
    string str;

    printable() = default;
    template<typename T>
    printable(const T &arg): str{to_string(arg)} {}
    printable(string str);
    printable(const char *arg);
    void __print() const;
    operator string() const;
    printable &operator=(const string &x);
    static printable empty;
};

printable operator+(const printable &a, const printable &b);
printable operator "" _pr(const char *str, size_t);

#endif //CALCULUS_PRINTABLE_H
