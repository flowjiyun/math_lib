#include "../src/mat2.hpp"
#include "../src/utils.hpp"
#include "../src/vec2.hpp"
#include "../src/vec3.hpp"
#include "../src/vec4.hpp"
#include <cassert>
#include <iostream>

int main() {
    int Error = 0;

    std::cout << "Vec Test" << std::endl;
    // test vec + vec
    {
        jlm::vec2 a = jlm::vec2(1.0f, 1.0f);
        jlm::vec2 b = jlm::vec2(2.0f, 2.0f);
        jlm::vec2 c = a + b;
        jlm::vec2 ans1 = jlm::vec2(3.0f, 3.0f);
        if (c != ans1) {
            Error++;
        }
        assert(c == ans1);

        c = -c;
        jlm::vec2 ans2 = jlm::vec2(0.0f, 0.0f);
    }
    // test vec + scalar
    {
        jlm::vec2 a = jlm::vec2(1.0f, 1.0f);
        jlm::vec2 b = jlm::vec2(2.0f, 2.0f);
        jlm::vec2 c = a + b;
        jlm::vec2 ans = jlm::vec2(3.0f, 3.0f);
        if (c != ans) {
            Error++;
        }
        assert(c == ans);
    }

    std::cout << "Mat Test" << std::endl;
    // test mat * vec
    {
        jlm::mat2 i = jlm::mat2(jlm::vec2::UnitX, jlm::vec2::UnitY);
        jlm::vec2 v = jlm::vec2(3.0f, 1.0f);
        jlm::vec2 d = i * v;
        if (v != d) {
            Error++;
        }
        assert(v == d);
    }
    // test mat * mat
    {
        jlm::mat2 a = jlm::mat2(jlm::vec2(1.0f, 3.0f), jlm::vec2(2.0f, 4.0f));
        jlm::mat2 ans =
            jlm::mat2(jlm::vec2(7.0f, 15.0f), jlm::vec2(10.0f, 22.0f));
        if (a * a != ans) {
            Error++;
        }
        assert(a * a == ans);
    }
    // test mat * scalar
    {
        jlm::mat2 a = jlm::mat2(jlm::vec2(1.0f, 3.0f), jlm::vec2(2.0f, 4.0f));
        jlm::mat2 ans = jlm::mat2(jlm::vec2(2.0f, 6.0f), jlm::vec2(4.0f, 8.0f));
        if (a * 2 != ans) {
            Error++;
        }
        assert(a * 2 == ans);
    }

    return Error;
}