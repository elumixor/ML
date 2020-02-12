////
//// Created by vlado on 4/2/20.
////
//
//#include <nn/network.h>
//#include <iterable.h>
//
///* Constructors */
//network::network() = default;
//network::network(cnetwork other) : layers(other.layers.size()) {
//    print("Copy network");
//
//    for (cval item : other.layers)
//        layers.push_back(item->copy());
//}
//network::network(network &&other) noexcept : layers{std::move(other.layers)} {
//    print("move network");
//}
//
///* Destructor */
//network::~network() {
//    for (var i{0u}; i < layers.size(); ++i)
//        delete layers[i];
//}
//
///* Member functions */
//tensor network::operator()(tensor in) {
//    for (cvar module : layers)
//        in = (*module)(in);
//
//    return in;
//}
//void network::backward(tensor dl) {
//    for (cvar module : reverse(layers))
//        dl = (*module).diff(dl);
//}
//void network::update(scalar learning_rate) {
//    for (cvar layer : layers)
//        (*layer).update(learning_rate);
//}
//
//
