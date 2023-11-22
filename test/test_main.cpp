#include "../src/mat2.hpp"
#include "../src/utils.hpp"
#include "../src/vec2.hpp"
#include <cassert>
#include <iostream>

int main() {
    int Error = 0;

    jlm::vec2 a = jlm::vec2(1.0f, 1.0f);
    jlm::vec2 b = jlm::vec2(2.0f, 2.0f);
    std::cout << a.x() << " " << a.y() << std::endl;

    jlm::vec2 c = a + b;
    std::cout << c.x() << " " << c.y() << std::endl;

    std::cout << *jlm::ValuePtr(c) << std::endl;
    std::cout << a.SizeSquared() << std::endl;
    std::cout << a.Size() << std::endl;

    std::cout << "Mat" << std::endl;
    // check mat * vec
    {
        jlm::mat2 i = jlm::mat2(jlm::vec2::UnitX, jlm::vec2::UnitY);
        jlm::vec2 v = jlm::vec2(3.0f, 1.0f);
        jlm::vec2 d = i * v;
        if (v != d) {
            Error++;
        }
    }
    // check mat * mat
    {
        jlm::mat2 a = jlm::mat2(jlm::vec2(1.0f, 3.0f), jlm::vec2(2.0f, 4.0f));
        jlm::mat2 ans =
            jlm::mat2(jlm::vec2(7.0f, 15.0f), jlm::vec2(10.0f, 22.0f));
        if (a * a != ans) {
            Error++;
        }
    }
    // check mat * scalar
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