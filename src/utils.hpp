#pragma once

#include "vec2.hpp"

namespace jlm {

const float* ValuePtr(const vec2& v) { return v.ptr(); }

float* ValuePtr(vec2& v) { return v.ptr(); }

// Todo: perspective
// Todo: translate
// Todo: scale
// Todo: rotate
// Todo: radians
// Todo: lookat
// Todo: dot
// Todo: cross
// Todo: normalize
// Todo: clamp

} // namespace jlm