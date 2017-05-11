#include "max.hpp"
#include <iostream>
#include <string>

int main()
{
    using namespace std::literals::string_literals;

    auto i = 42;
    std::cout << "i: " << i << '\n';
    std::cout << "max(7, i):   " << ::max(7, i) << '\n';

    auto f1 = 3.4;
    auto f2 = -6.7;
    std::cout << "f1: " << f1 << '\n';
    std::cout << "f2: " << f2 << '\n';
    std::cout << "max(f1, f2): " << ::max(f1, f2) << '\n';

    auto s1 = "mathematics"s;
    auto s2 = "math"s;

    std::cout << "s1: " << s1 << '\n';
    std::cout << "s2: " << s2 << '\n';
    std::cout << "max(s1, s2): " << ::max(s1, s2) << '\n';

    // no automatic type deduction
    std::cout << "max(i, f1):  " << ::max(static_cast<double>(i), f1) << '\n';
    std::cout << "max(i, f1):  " << ::max<double>(i, f1) << '\n';
}
