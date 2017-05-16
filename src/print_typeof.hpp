#pragma once

#include <iostream>
#include <typeinfo>

// Declaring template
template<typename T>
void print_typeof(T const&);

// Implementation/definition of a template
template<typename T>
void print_typeof(T const& x)
{
    std::cout << typeid(x).name() << '\n';
}
