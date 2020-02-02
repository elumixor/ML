//
// Created by vlado on 2/2/20.
//

#include "../include/exceptions.h"
#include "../include/def.h"

ml_exception::~ml_exception() noexcept = default;
const char *ml_exception::what() const noexcept {
    return msg.c_str();
}
