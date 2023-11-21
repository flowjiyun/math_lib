#include "../src/mat2.hpp"
#include "../src/utils.hpp"
#include "../src/vec2.hpp"
#include <iostream>

int main() {
    // int Error = 0;

    jlm::vec2 a = jlm::vec2(1.0f, 1.0f);
    jlm::vec2 b = jlm::vec2(2.0f, 2.0f);
    std::cout << a.x() << " " << a.y() << std::endl;

    jlm::vec2 c = a + b;
    std::cout << c.x() << " " << c.y() << std::endl;

    std::cout << *jlm::ValuePtr(c) << std::endl;
    std::cout << a.SizeSquared() << std::endl;
    std::cout << a.Size() << std::endl;

    std::cout << "Mat" << std::endl;
    jlm::mat2 a = jlm::mat2();
    return 0;
}