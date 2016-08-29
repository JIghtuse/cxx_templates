#include <iostream>

// Took a type, return a number

template<class T>
struct rank {
    static constexpr size_t value = 0u;
};

template<class U, size_t N>
struct rank<U[N]> {
    static constexpr size_t value = 1u + rank<U>::value;
};

int main()
{
    std::cout << "rank of int: " << rank<int>::value << '\n';
    std::cout << "rank of int[9]: " << rank<int[9]>::value << '\n';
    std::cout << "rank of int[9][9]: " << rank<int[9][9]>::value << '\n';
    std::cout << "rank of int[9][9][9]: " << rank<int[9][9][9]>::value << '\n';
}
