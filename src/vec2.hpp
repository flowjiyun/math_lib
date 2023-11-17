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
} // namespace jlm