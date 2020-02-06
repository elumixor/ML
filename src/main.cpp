//
// Created by vlado on 2/2/20.
//

#include <nn/network.h>
#include <output/printable.h>
#include <math/matht.h>
#include <iterable.h>

//declare(fc1) : layer {
//    layer_name("fc1");
//    layer *copy() const override { return new fc1(*this); }
//    tensor operator()(const tensor &input) override {
//        return tensor();
//    }
//    tensor diff(const tensor &dl) override {
//        return tensor();
//    }
//    void update(num learning_rate) override {
//
//    }
//};
//
//declare(fc2) : layer {
//    layer_name("fc2");
//    layer *copy() const override { return new fc2(*this); }
//    tensor operator()(const tensor &input) override {
//        return tensor();
//    }
//    tensor diff(const tensor &dl) override {
//        return tensor();
//    }
//    void update(num learning_rate) override {
//
//    }
//};
struct A {
    struct iterator {
        using iterator_category = std::random_access_iterator_tag;

        iterator(nat i = 0) : i_{i} {}


        nat i_{0};
        friend struct A;

        long int operator*() const { return i_; }
        const iterator &operator++() {
            ++i_;
            return *this;
        }

        iterator operator++(int) {
            const iterator copy(*this);
            ++i_;
            return copy;
        }

        bool operator==(const iterator &other) const { return i_ == other.i_; }
        bool operator!=(const iterator &other) const { return i_ != other.i_; }
    };

    [[nodiscard]] iterator begin() const { return iterator(); }
    [[nodiscard]] iterator end() const { return iterator(10); }
};


int main() {
    tensor W{{1, 2},
             {3, 4}};

    tensor x{{1, 1},
             {1, 3}};

    A a;

    for (cval item: W.indices())
        print(item);

//    for (cval item : a)
//        print(item);

//    for
//    print(W);
//    print(dot(W, x, 0, 0));

//    >>> a = np.arange(60.).reshape(3,4,5)
//    >>> b = np.arange(24.).reshape(4,3,2)
//    >>> c = np.tensordot(a,b, axes=([1,0],[0,1]))
//    >>> c.shape

//    print(dot(tensor({3, 4, 5}, 60), tensor({4, 3, 2}, 24), {1, 0}, {0, 1})));
}
