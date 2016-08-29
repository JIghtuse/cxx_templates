#include <iostream>
#include <limits>

template<int N>
struct Abs {
    static_assert(N != std::numeric_limits<decltype(N)>::min(), "");
    static constexpr int value = (N < 0) ? -N : N;
};


template<int N>
constexpr void print_abs()
{
    std::cout << "Abs of " << N << ": " << Abs<N>::value << '\n';
}

int main()
{
    print_abs<3>();
    print_abs<0>();
    print_abs<-3>();
}
