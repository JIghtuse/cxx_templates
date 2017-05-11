// Function template overloading example
#include <cstring>
#include <iostream>
#include <string>

// max of two ints
inline int const& max(int const& a, int const& b)
{
    return a < b ? b : a;
}

// max of two values of some type
template<typename T>
inline T const& max(T const& a, T const& b)
{
    return a < b ? b : a;
}

// max of three values of some type
template<typename T>
inline T const& max(T const& a, T const& b, T const& c)
{
    return max(max(a, b), c);
}

// max of two pointers
template<typename T>
inline T* const& max(T* const& a, T* const& b)
{
    return *a < *b ? b : a;
}

// max of two C-strings
inline char const* const& max(char const* const& a,
                              char const* const& b)
{
    return std::strcmp(a, b) < 0 ? b : a;
}


int main()
{
    using namespace std::literals::string_literals;
    int a = 7;
    int b = 42;
    auto s = "hey"s;
    auto t = "you"s;
    auto* p1 = &b;
    auto* p2 = &a;
    char const* s1 = "Noone";
    char const* s2 = "Sansa";

    std::cout << "a:  " << a << '\n';
    std::cout << "b:  " << b << '\n';
    std::cout << "s:  " << s << '\n';
    std::cout << "t:  " << t << '\n';
    std::cout << "p1: " << p1 << '\n';
    std::cout << "p2: " << p2 << '\n';
    std::cout << "s1: " << s1 << '\n';
    std::cout << "s2: " << s2 << '\n';

    std::cout << ::max(a, b, 68) << '\n';      // three-argument template
    std::cout << ::max(7.0, 42.0) << '\n';     // max<double> (deduction)
    std::cout << ::max('a', 'b') << '\n';      // max<char> (deduction)
    std::cout << ::max(a, b) << '\n';          // max (non-templated function for ints)
    std::cout << ::max<>(a, b) << '\n';        // max<int> (deduction)
    std::cout << ::max<double>(a, b) << '\n';  // max<double> (explicit initiation)
    std::cout << ::max('a', 42.7) << '\n';     // max (non-templated function, conversion)

    std::cout << ::max(s, t) << '\n';          // max<std::string>
    std::cout << *::max(p1, p2) << '\n';       // max (non-templated function for pointers)
    std::cout << ::max(s1, s2) << '\n';        // max (non-templated function for const char*)

}
