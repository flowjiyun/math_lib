#include "utils.hpp"

using namespace jlm;

const float* ValuePtr(const vec2& v) { return &v.mX; }

float* ValuePtr(vec2& v) { return &v.mX; }