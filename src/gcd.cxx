#include <iostream>

template<unsigned M, unsigned N>
struct gcd {
    static constexpr int value = gcd<N, M % N>::value;
};

template<unsigned M>
struct gcd<M, 0> {
    static_assert(M != 0);
    static constexpr int value = M;
};

int main()
{
    std::cout << "gcd of 8 and 12: " << gcd<8, 12>::value << '\n';
    std::cout << "gcd of 8 and 8: " << gcd<8, 8>::value << '\n';
    std::cout << "gcd of 4 and 0: " << gcd<4, 0>::value << '\n';
    std::cout << "gcd of 0 and 4: " << gcd<0, 4>::value << '\n';
    std::cout << "gcd of 0 and 0: " << gcd<0, 0>::value << '\n';
}
