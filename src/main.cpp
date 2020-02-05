//
// Created by vlado on 2/2/20.
//

#include <nn/network.h>
#include <output/printable.h>

declare(fc1) : layer {
    layer_name("fc1");
    layer *copy() const override { return new fc1(*this); }
    tensor operator()(const tensor &input) override {
        return tensor();
    }
    tensor diff(const tensor &dl) override {
        return tensor();
    }
    void update(num learning_rate) override {

    }
};

declare(fc2) : layer {
    layer_name("fc2");
    layer *copy() const override { return new fc2(*this); }
    tensor operator()(const tensor &input) override {
        return tensor();
    }
    tensor diff(const tensor &dl) override {
        return tensor();
    }
    void update(num learning_rate) override {

    }
};


int main() {
    network k;
    print(k({1, 2, 3}));
}
