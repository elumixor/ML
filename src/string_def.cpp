//
// Created by vlado on 2/2/20.
//

#include "../include/def.h"
#include "../include/tensor.h"
#include "../include/string_def.h"


string format_elements(ctensor tensor, uint depth = 1) {
    if (tensor.rank == 1) return to_string(tensor.elements);

    string res{'['};

    const auto subdim = tensor.subdim();
    const auto size = subdim.size();

    for (auto i = 0u; i < size; ++i) {
        res += format_elements(subdim[i], depth + 1);

        if (i < size - 1) res += string(depth, '\n') + string(depth, ' ');
    }

    res += ']';
    return res;
}

string to_string(ctensor tensor) {
    return "tensor ("_pr + tensor.rank + "): " + tensor.dimensions + "\n" + format_elements(tensor);
}
