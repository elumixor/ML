////
//// Created by vlado on 4/2/20.
////
//
//#ifndef CALCULUS_NETWORK_H
//#define CALCULUS_NETWORK_H
//
//#include <declarations.h>
//#include <math/tensor.h>
//#include <nn/layer.h>
//
//struct network;
//using cnetwork = network cref;
//
//struct network {
//    /* Fields */
//    /**
//     * Network's layers. Result of computation of each layer is forwarded into a next one.
//     * Layers may have learnable parameters (weights) and store gradients,
//     * or may simply be functions with no such parameters.
//     */
//    array<layer *> layers;
//
//    /* Constructors */
//    /**
//     * Implicit conversion constructor from a layer.
//     * Creates a network with the single copy of that layer.
//     */
//    template<typename T>
//    explicit network(const T &l) : layers{new T(l)} {}
//    /** Default empty constructor. Does not create any layers. */
//    network();
//    /** Copy constructor. Creates a deep copy of allocated layers. */
//    network(cnetwork &);
//    /** Move constructors. Moves pointers of allocated layers to a new network. */
//    network(network &&) noexcept;
//    /** Frees layers, allocated on the heap */
//    ~network();
//
//    /* Member functions */
//    /**
//     * Performs a forward pass.
//     * Applies a network to an input and returns output.
//     * Stores computed values for layers to be later used in backpropagation.
//     * @param in Batch of input data
//     * @return Computed output tensor.
//     */
//    tensor operator()(tensor in);
//    /**
//     * Performs a backward pass.
//     * Takes a loss tensor and computes gradient wrt learnable parameters.
//     * Stores computed gradient inside layers.
//     * @param dl Loss derivative
//     */
//    void backward(tensor dl);
//    /**
//     * Updates network wrt computed gradient.
//     * @param learning_rate Multiplier for the gradient.
//     */
//    void update(scalar learning_rate);
//};
//
///**
// * Appends new layer to the end of the network.
// * @return Network
// */
//template<typename T>
//network operator>>(network net, const T &l) {
//    net.layers.push_back(new T(l));
//    return net;
//}
//
//#endif //CALCULUS_NETWORK_H
