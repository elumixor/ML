//
// Created by vlado on 2/2/20.
//

#include <declarations.h>
#include <math/tensor.h>
#include <output/to_string.h>
//#include <nn/network.h>
//#include <output/to_string.h>
//#include <output/printable.h>
//#include <math/matht.h>


string format_elements(tensor_view cref view, nat depth = 1, bool not_last = false) {
    if (view.is_vector()) return to_string(view.vector());

    string res{'['};

    val size{view.count()};

    var i{0u};
    for (cval subview : view) {
        res += format_elements(subview, depth + 1, i < size - 1);
        if (i < size - 1) res += '\n' + string(depth, ' ');
        i++;
    }

    res += ']';

    if (depth > 1 && not_last)
        res += string(depth - 1, '\n');

    return res;
}

string to_string(tensor_view cref view) {
    if (view.dimensions.size == 0) return to_string(view.data_start[0]);
    return "T"_pr + view.dimensions.size + to_string(view.dimensions, '(', ')') + "\n" + format_elements(view);
}

string to_string(flat_view cref view, char opening_bracket, char closing_bracket, string cref separator) {
    string result{opening_bracket};

    for (cval item : view)
        result += to_string(item) + separator;

    val size{separator.length()};
    forsize result.pop_back();

    result += closing_bracket;
    return result;
}
//string to_string(clayer layer) {
//    return layer.name();
//}
//string to_string(cnetwork net) {
//    string str{"NN: "};
//    val size = net.layers.size();
//    for (var i{0u}; i < size; ++i) {
//        str += to_string(*net.layers[i]);
//
//        if (i < size - 1)
//            str += " >> ";
//    }
//
//    return str;
//}
////string to_string(indices cref itr) {
////    array<vnat> result;
////
////    val size{product(itr.dimensions)};
////    result.reserve(size);
////
////    for (cval item : itr)
////        result.push_back(item);
////
////    return to_string(result, '[', ']', "\n ");
////}
