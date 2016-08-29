#include "enable_if.hpp"
#include <cstdint>
#include <iostream>
#include <type_traits>

template<class T>
enable_if_t<std::is_integral<T>::value, intmax_t> f(T val) {
    return 0;
}

template<class T>
enable_if_t<std::is_floating_point<T>::value, long double> f(T val) {
    return 1;
}

int main()
{
    std::cout << "f for int: " << f(3) << '\n';
    std::cout << "f for double: " << f(3.1415) << '\n';
}
