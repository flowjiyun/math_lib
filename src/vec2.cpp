#include "vec2.hpp"

using namespace jlm;

constexpr vec2::vec2(float x, float y) : mX(x), mY(y) {}

constexpr float jlm::vec2::x() const
{
    return mX;
}

constexpr float jlm::vec2::y() const
{
    return mY;
}
