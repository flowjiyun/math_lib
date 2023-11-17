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

constexpr float jlm::vec2::operator[](uint32_t index) const
{
    assert(index < Dimension);
    return mScalars[index];
}

constexpr float& jlm::vec2::operator[](uint32_t index)
{
    assert(index < Dimension);
    return mScalars[index];
}

constexpr vec2 jlm::vec2::operator+(const vec2 &rhs) const
{
    return vec2(mX + rhs.mX, mY + rhs.mY);
}

constexpr vec2 jlm::vec2::operator-() const
{
    return vec2(-mX, -mY);
}

constexpr vec2 jlm::vec2::operator-(const vec2 &rhs) const
{
    return vec2(mX - rhs.mX, mY - rhs.mY);
}

constexpr vec2 jlm::vec2::operator*(float scalar) const
{
    return vec2(mX * scalar, mY * scalar);
}

constexpr vec2 jlm::vec2::operator*(const vec2 &rhs) const
{
    return vec2(mX * rhs.mX, mY * rhs.mY);
}

constexpr vec2 jlm::vec2::operator/(float scalar) const
{
    return vec2(mX / scalar, mY / scalar);
}

constexpr vec2 &jlm::vec2::operator+=(const vec2 &rhs)
{
    mX += rhs.mX;
    mY += rhs.mY;
    return *this;
}

constexpr vec2 &jlm::vec2::operator-=(const vec2 &rhs)
{
    mX -= rhs.mX;
    mY -= rhs.mY;
    return *this;
}

constexpr vec2 &jlm::vec2::operator*=(float scalar)
{
    mX *= scalar;
    mY *= scalar;
    return *this;
}

constexpr vec2 &jlm::vec2::operator/=(float scalar)
{
    mX /= scalar;
    mY /= scalar;
    return *this;
}

constexpr vec2 &jlm::vec2::operator*=(const vec2 &rhs)
{
    mX /= rhs.mX;
    mY /= rhs.mY;
    return *this;
}
