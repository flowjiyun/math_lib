#pragma once

#include <array>
#include <cassert>

namespace jlm {
class vec2 {
  public:
    // constructor
    constexpr vec2() = default;
    explicit constexpr vec2(float x, float y);

    // copy constructor & assignment operator
    constexpr vec2(const vec2& other) = default;
    constexpr vec2& operator=(const vec2& other) = default;

    // getter
    constexpr float x() const;
    constexpr float y() const;
    const float* ptr() const;
    float* ptr();

    // accessor
    constexpr float operator[](uint32_t index) const;
    constexpr float& operator[](uint32_t index);

    // operator
    constexpr vec2 operator+(const vec2& rhs) const;
    constexpr vec2 operator-() const;
    constexpr vec2 operator-(const vec2& rhs) const;
    constexpr vec2 operator*(float scalar) const;
    constexpr vec2 operator*(const vec2& rhs) const;
    constexpr vec2 operator/(float scalar) const;
    constexpr vec2& operator+=(const vec2& rhs);
    constexpr vec2& operator-=(const vec2& rhs);
    constexpr vec2& operator*=(float scalar);
    constexpr vec2& operator/=(float scalar);
    constexpr vec2& operator*=(const vec2& rhs);

  private:
    static constexpr uint32_t Dimension{2};
    union {
        struct {
            float mX, mY;
        };
        std::array<float, Dimension> mScalars{0.0f, 0.0f};
    };
};

constexpr vec2::vec2(float x, float y) : mX(x), mY(y) {}

constexpr float vec2::x() const { return mX; }

constexpr float vec2::y() const { return mY; }

const float* vec2::ptr() const { return &mX; }
float* vec2::ptr() { return &mX; }

constexpr float vec2::operator[](uint32_t index) const {
    assert(index < Dimension);
    return mScalars[index];
}

constexpr float& vec2::operator[](uint32_t index) {
    assert(index < Dimension);
    return mScalars[index];
}

constexpr vec2 vec2::operator+(const vec2& rhs) const {
    return vec2(mX + rhs.mX, mY + rhs.mY);
}

constexpr vec2 vec2::operator-() const { return vec2(-mX, -mY); }

constexpr vec2 vec2::operator-(const vec2& rhs) const {
    return vec2(mX - rhs.mX, mY - rhs.mY);
}

constexpr vec2 vec2::operator*(float scalar) const {
    return vec2(mX * scalar, mY * scalar);
}

constexpr vec2 vec2::operator*(const vec2& rhs) const {
    return vec2(mX * rhs.mX, mY * rhs.mY);
}

constexpr vec2 vec2::operator/(float scalar) const {
    return vec2(mX / scalar, mY / scalar);
}

constexpr vec2& vec2::operator+=(const vec2& rhs) {
    mX += rhs.mX;
    mY += rhs.mY;
    return *this;
}

constexpr vec2& vec2::operator-=(const vec2& rhs) {
    mX -= rhs.mX;
    mY -= rhs.mY;
    return *this;
}

constexpr vec2& vec2::operator*=(float scalar) {
    mX *= scalar;
    mY *= scalar;
    return *this;
}

constexpr vec2& vec2::operator/=(float scalar) {
    mX /= scalar;
    mY /= scalar;
    return *this;
}

constexpr vec2& vec2::operator*=(const vec2& rhs) {
    mX /= rhs.mX;
    mY /= rhs.mY;
    return *this;
}
} // namespace jlm