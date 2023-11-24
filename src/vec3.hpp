#pragma once

#include "common.hpp"
namespace jlm {
class vec3 {
  public:
    // constructor
    constexpr vec3() = default;
    explicit constexpr vec3(float x, float y, float z);

    // copy constructor & assignment operator
    constexpr vec3(const vec3& other) = default;
    constexpr vec3& operator=(const vec3& other) = default;

    // getter
    constexpr float x() const;
    constexpr float y() const;
    constexpr float z() const;
    const float* ptr() const;
    float* ptr();

    // accessor
    constexpr float operator[](uint32_t index) const;
    constexpr float& operator[](uint32_t index);

    // operator
    constexpr vec3 operator+(const vec3& rhs) const;
    constexpr vec3 operator-() const;
    constexpr vec3 operator-(const vec3& rhs) const;
    constexpr vec3 operator*(float scalar) const;
    constexpr vec3 operator*(const vec3& rhs) const;
    constexpr vec3 operator/(float scalar) const;
    constexpr vec3& operator+=(const vec3& rhs);
    constexpr vec3& operator-=(const vec3& rhs);
    constexpr vec3& operator*=(float scalar);
    constexpr vec3& operator/=(float scalar);
    constexpr vec3& operator*=(const vec3& rhs);
    bool operator==(const vec3& rhs) const;
    bool operator!=(const vec3& rhs) const;

    // member fucntion
    constexpr float SizeSquared() const;
    float Size() const;
    constexpr float Dot(const vec3& rhs) const;

    static const vec3 UnitX;
    static const vec3 UnitY;
    static const vec3 UnitZ;

  private:
    static constexpr uint32_t Dimension{3};
    union {
        struct {
            float mX, mY, mZ;
        };
        std::array<float, Dimension> mScalars{0.0f, 0.0f, 0.0f};
    };
};

const vec3 vec3::UnitX(1.0f, 0.0f, 0.0f);
const vec3 vec3::UnitY(0.0f, 1.0f, 0.0f);
const vec3 vec3::UnitZ(0.0f, 0.0f, 1.0f);

constexpr vec3::vec3(float x, float y, float z) : mX(x), mY(y), mZ(z) {}

constexpr float vec3::x() const { return mX; }

constexpr float vec3::y() const { return mY; }

constexpr float vec3::z() const { return mZ; }

const float* vec3::ptr() const { return &mX; }
float* vec3::ptr() { return &mX; }

constexpr float vec3::operator[](uint32_t index) const {
    assert(index < Dimension);
    return mScalars[index];
}

constexpr float& vec3::operator[](uint32_t index) {
    assert(index < Dimension);
    return mScalars[index];
}

constexpr vec3 vec3::operator+(const vec3& rhs) const {
    return vec3(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ);
}

constexpr vec3 vec3::operator-() const { return vec3(-mX, -mY, -mZ); }

constexpr vec3 vec3::operator-(const vec3& rhs) const {
    return vec3(mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ);
}

constexpr vec3 vec3::operator*(float scalar) const {
    return vec3(mX * scalar, mY * scalar, mZ * scalar);
}

constexpr vec3 vec3::operator*(const vec3& rhs) const {
    return vec3(mX * rhs.mX, mY * rhs.mY, mZ * rhs.mZ);
}

constexpr vec3 vec3::operator/(float scalar) const {
    return vec3(mX / scalar, mY / scalar, mZ / scalar);
}

constexpr vec3& vec3::operator+=(const vec3& rhs) {
    mX += rhs.mX;
    mY += rhs.mY;
    mZ += rhs.mZ;
    return *this;
}

constexpr vec3& vec3::operator-=(const vec3& rhs) {
    mX -= rhs.mX;
    mY -= rhs.mY;
    mZ -= rhs.mZ;
    return *this;
}

constexpr vec3& vec3::operator*=(float scalar) {
    mX *= scalar;
    mY *= scalar;
    mZ *= scalar;
    return *this;
}

constexpr vec3& vec3::operator/=(float scalar) {
    mX /= scalar;
    mY /= scalar;
    mZ /= scalar;
    return *this;
}

constexpr vec3& vec3::operator*=(const vec3& rhs) {
    mX /= rhs.mX;
    mY /= rhs.mY;
    mZ /= rhs.mZ;
    return *this;
}

constexpr float vec3::SizeSquared() const {
    return mX * mX + mY * mY + mZ * mZ;
}

float vec3::Size() const { return sqrtf(SizeSquared()); }

constexpr float vec3::Dot(const vec3& rhs) const {
    return mX * rhs.mX + mY * rhs.mY + mZ * rhs.mZ;
}

bool vec3::operator==(const vec3& rhs) const {
    if (mScalars == rhs.mScalars) {
        return true;
    }
    return false;
}
bool vec3::operator!=(const vec3& rhs) const {
    if (mScalars != rhs.mScalars) {
        return true;
    }
    return false;
}
} // namespace jlm