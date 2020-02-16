//
// Created by vlado on 2/2/20.
//

#include <common/declarations.h>
#include <collections/tensor.h>
#include <output/to_string.h>
//#include <nn/network.h>
//#include <output/to_string.h>
//#include <output/printable.h>
//#include <math/matht.h>


string format_elements(tensor cref t, nat depth = 1, bool not_last = false) {
    if (t.is_vector()) return to_string(t.elements);

    string res{'['};

    val size{t.subdim_count()};

    var i{0u};
    for (cval t1 : t) {
        res += format_elements(t1, depth + 1, i < size - 1);
        if (i < size - 1) res += '\n' + string(depth, ' ');
        i++;
    }

    res += ']';

    if (depth > 1 && not_last)
        res += string(depth - 1, '\n');

    return res;
}

string to_string(tensor cref t) {
    if (t.is_scalar()) return to_string(t.elements[0]);

    return "T"_pr + t.dimensions.size + to_string(t.dimensions, '(', ')') + "\n" + format_elements(t);
}
string to_string(composite_index cref index) {
    return "composite_index: dim: "_pr + index.dimensions + " sizes: " + index.sizes + " current: " + index.current_index;
}

string to_string(vec cref view, char opening_bracket, char closing_bracket, string cref separator) {
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
////    collections<vnat> result;
////
////    val size{product(itr.dimensions)};
////    result.reserve(size);
////
////    for (cval item : itr)
////        result.push_back(item);
////
////    return to_string(result, '[', ']', "\n ");
////}
