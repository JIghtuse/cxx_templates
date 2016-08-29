#include <iostream>
#include "enable_if.hpp"

template<int N, int D>
struct Div {
    enable_if_t<(D != 0), int> operator()() {
        return N / D;
    }
};

template<int N, int D>
void print_divs()
{
    auto i = Div<N, D>();
    std::cout << N << " / " << D << " == " << i() << '\n';
}

int main()
{
    print_divs<4, 2>();
    print_divs<2, 4>();
    print_divs<2, 0>();
}
