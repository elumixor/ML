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

int main() {
    tensor W{{1, 2},
             {3, 4}};

    tensor x{{1, 2},
             {1, 3},
             {1, 4}};

    tensor Y{{{1, 1}, {2, 2}},
             {{1, 0}, {3, 5}},
             {{1, 0}, {4, 5}}};


    print(x.dimensions);
    print(x.vector(0, {0}));
    print(x.vector(0, {1}));

    print(x.vector(1, {0}));
    print(x.vector(1, {1}));
    print(x.vector(1, {2}));

    print_line();

    print(W.vector(0, {0}));
    print(W.vector(0, {1}));
    print(W.vector(1, {0}));
    print(W.vector(1, {1}));

    print_line();
    print(Y);
    print_line();

    print(Y.vector(0, {0, 0}));
    print(Y.vector(1, {0, 0}));
    print(Y.vector(2, {0, 0}));

    print_line();
    print(Y.vector(0, {1, 0}));
    print(Y.vector(1, {1, 0}));
    print(Y.vector(2, {1, 0}));
    print_line();
    print(Y.vector(0, {0, 1}));
    print(Y.vector(1, {0, 1}));
    print(Y.vector(2, {0, 1}));
    print_line();
    print(Y.vector(0, {1, 1}));
    print(Y.vector(1, {1, 1}));
    print(Y.vector(2, {1, 1}));
//    print(dot(W, x, 0, 0));


//    >>> a = np.arange(60.).reshape(3,4,5)
//    >>> b = np.arange(24.).reshape(4,3,2)
//    >>> c = np.tensordot(a,b, axes=([1,0],[0,1]))
//    >>> c.shape

//    print(dot(tensor({3, 4, 5}, 60), tensor({4, 3, 2}, 24), {1, 0}, {0, 1})));
}
