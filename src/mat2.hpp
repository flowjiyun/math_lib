#pragma once

#include "common.hpp"
#include "vec2.hpp"

namespace jlm {
class mat2 {
  public:
    // constructor
    constexpr mat2() = default;
    explicit constexpr mat2(const vec2& e1, const vec2& e2);

    // copy constructor & assignment operator
    constexpr mat2(const mat2& other) = default;
    constexpr mat2& operator=(const mat2& other) = default;

    // accessor
    const vec2& operator[](uint32_t index) const;
    vec2& operator[](uint32_t index);

    // operator
    mat2 operator+(const mat2& rhs) const;
    mat2 operator*(float scalar) const;
    vec2 operator*(const vec2& rhs) const;
    mat2 operator*(const mat2& rhs) const;

    // member function
    mat2 Transpose() const;

  private:
    static constexpr uint32_t Rank{2};

    std::array<vec2, Rank> mCols{vec2::UnitX, vec2::UnitY};
};

constexpr mat2::mat2(const vec2& e1, const vec2& e2) : mCols({e1, e2}) {}

const vec2& mat2::operator[](uint32_t index) const {
    assert(index < Rank);
    return mCols[index];
}
vec2& mat2::operator[](uint32_t index) {
    assert(index < Rank);
    return mCols[index];
}

mat2 mat2::operator+(const mat2& rhs) const {
    return mat2(mCols[0] + rhs.mCols[0], mCols[1] + rhs.mCols[1]);
}

mat2 mat2::Transpose() const {
    return mat2(vec2(mCols[0].x(), mCols[1].x()),
                vec2(mCols[0].y(), mCols[1].y()));
}

mat2 mat2::operator*(float scalar) const {
    return mat2(mCols[0] * scalar, mCols[1] * scalar);
}

vec2 mat2::operator*(const vec2& rhs) const {
    mat2 result = Transpose();
    return vec2(result[0].Dot(rhs), result[1].Dot(rhs));
}

mat2 mat2::operator*(const mat2& rhs) const {
    mat2 result = Transpose();
    return mat2(vec2(result[0].Dot(rhs[0]), result[1].Dot(rhs[0])),
                vec2(result[0].Dot(rhs[1]), result[1].Dot(rhs[1])));
}
} // namespace jlm