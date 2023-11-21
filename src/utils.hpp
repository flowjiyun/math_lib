#pragma once

#include "vec2.hpp"

namespace jlm {

const float* ValuePtr(const vec2& v) { return v.ptr(); }

float* ValuePtr(vec2& v) { return v.ptr(); }
} // namespace jlm