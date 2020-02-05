//
// Created by vlado on 2/2/20.
//

#include <def.h>
#include <output.h>
#include <math/tensor.h>
#include <nn/network.h>

string format_elements(ctensor tensor, nat depth = 1, bool not_last = false) {
    if (tensor.rank == 1) return to_string(tensor.elements);

    string res{'['};

    const auto subdim = tensor.subdim();
    const auto size = subdim.size();

    for (auto i = 0u; i < size; ++i) {
        res += format_elements(subdim[i], depth + 1, i < size - 1);
        if (i < size - 1) res += '\n' + string(depth, ' ');
    }

    res += ']';

    if (depth > 1 && not_last)
        res += string(depth - 1, '\n');

    return res;
}

string to_string(ctensor tensor) {
    if (tensor.rank == 0) return to_string(tensor.elements[0]);
    return "T"_pr + tensor.rank + to_string(tensor.dimensions, '(', ')') + "\n" + format_elements(tensor);
}
string to_string(clayer layer) {
    return layer.name();
}
string to_string(cnetwork net) {
    string str{"NN: "};
    val size = net.layers.size();
    for (var i{0u}; i < size; ++i) {
        str += to_string(*net.layers[i]);

        if (i < size - 1)
            str += " >> ";
    }

    return str;
}