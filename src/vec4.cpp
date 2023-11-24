#pragma once

#include "common.hpp"
namespace jlm {
class vec4 {
  public:
    // constructor
    constexpr vec4() = default;
    explicit constexpr vec4(float x, float y, float z, float w);

    // copy constructor & assignment operator
    constexpr vec4(const vec4& other) = default;
    constexpr vec4& operator=(const vec4& other) = default;

    // getter
    constexpr float x() const;
    constexpr float y() const;
    constexpr float z() const;
    constexpr float w() const;
    const float* ptr() const;
    float* ptr();

    // accessor
    constexpr float operator[](uint32_t index) const;
    constexpr float& operator[](uint32_t index);

    // operator
    constexpr vec4 operator+(const vec4& rhs) const;
    constexpr vec4 operator-() const;
    constexpr vec4 operator-(const vec4& rhs) const;
    constexpr vec4 operator*(float scalar) const;
    constexpr vec4 operator*(const vec4& rhs) const;
    constexpr vec4 operator/(float scalar) const;
    constexpr vec4& operator+=(const vec4& rhs);
    constexpr vec4& operator-=(const vec4& rhs);
    constexpr vec4& operator*=(float scalar);
    constexpr vec4& operator/=(float scalar);
    constexpr vec4& operator*=(const vec4& rhs);
    bool operator==(const vec4& rhs) const;
    bool operator!=(const vec4& rhs) const;

    // member fucntion
    constexpr float SizeSquared() const;
    float Size() const;
    constexpr float Dot(const vec4& rhs) const;

    static const vec4 UnitX;
    static const vec4 UnitY;
    static const vec4 UnitZ;
    static const vec4 UnitW;

  private:
    static constexpr uint32_t Dimension{4};
    union {
        struct {
            float mX, mY, mZ, mW;
        };
        std::array<float, Dimension> mScalars{0.0f, 0.0f, 0.0f, 0.0f};
    };
};

const vec4 vec4::UnitX(1.0f, 0.0f, 0.0f, 0.0f);
const vec4 vec4::UnitY(0.0f, 1.0f, 0.0f, 0.0f);
const vec4 vec4::UnitZ(0.0f, 0.0f, 1.0f, 0.0f);
const vec4 vec4::UnitW(0.0f, 0.0f, 0.0f, 1.0f);

constexpr vec4::vec4(float x, float y, float z, float w)
    : mX(x), mY(y), mZ(z), mW(w) {}

constexpr float vec4::x() const { return mX; }

constexpr float vec4::y() const { return mY; }

constexpr float vec4::z() const { return mZ; }

constexpr float vec4::w() const { return mW; }

const float* vec4::ptr() const { return &mX; }
float* vec4::ptr() { return &mX; }

constexpr float vec4::operator[](uint32_t index) const {
    assert(index < Dimension);
    return mScalars[index];
}

constexpr float& vec4::operator[](uint32_t index) {
    assert(index < Dimension);
    return mScalars[index];
}

constexpr vec4 vec4::operator+(const vec4& rhs) const {
    return vec4(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ, mW + rhs.mW);
}

constexpr vec4 vec4::operator-() const { return vec4(-mX, -mY, -mZ, -mW); }

constexpr vec4 vec4::operator-(const vec4& rhs) const {
    return vec4(mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ, mW - rhs.mW);
}

constexpr vec4 vec4::operator*(float scalar) const {
    return vec4(mX * scalar, mY * scalar, mZ * scalar, mW * scalar);
}

constexpr vec4 vec4::operator*(const vec4& rhs) const {
    return vec4(mX * rhs.mX, mY * rhs.mY, mZ * rhs.mZ, mW * rhs.mW);
}

constexpr vec4 vec4::operator/(float scalar) const {
    return vec4(mX / scalar, mY / scalar, mZ / scalar, mW / scalar);
}

constexpr vec4& vec4::operator+=(const vec4& rhs) {
    mX += rhs.mX;
    mY += rhs.mY;
    mZ += rhs.mZ;
    mW += rhs.mW;
    return *this;
}

constexpr vec4& vec4::operator-=(const vec4& rhs) {
    mX -= rhs.mX;
    mY -= rhs.mY;
    mZ -= rhs.mZ;
    mW -= rhs.mW;
    return *this;
}

constexpr vec4& vec4::operator*=(float scalar) {
    mX *= scalar;
    mY *= scalar;
    mZ *= scalar;
    mW *= scalar;
    return *this;
}

constexpr vec4& vec4::operator/=(float scalar) {
    mX /= scalar;
    mY /= scalar;
    mZ /= scalar;
    mW /= scalar;
    return *this;
}

constexpr vec4& vec4::operator*=(const vec4& rhs) {
    mX /= rhs.mX;
    mY /= rhs.mY;
    mZ /= rhs.mZ;
    mW /= rhs.mW;
    return *this;
}

constexpr float vec4::SizeSquared() const {
    return mX * mX + mY * mY + mZ * mZ + mW * mW;
}

float vec4::Size() const { return sqrtf(SizeSquared()); }

constexpr float vec4::Dot(const vec4& rhs) const {
    return mX * rhs.mX + mY * rhs.mY + mZ * rhs.mZ + mW * rhs.mW;
}

bool vec4::operator==(const vec4& rhs) const {
    if (mScalars == rhs.mScalars) {
        return true;
    }
    return false;
}
bool vec4::operator!=(const vec4& rhs) const {
    if (mScalars != rhs.mScalars) {
        return true;
    }
    return false;
}
} // namespace jlm