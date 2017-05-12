#include "partial_specialization.hpp"

int main()
{
    MyClass<int, float> mif;      // MyClass<T1, T2>
    MyClass<float, float> mff;    // MyClass<T, T>
    MyClass<float, int> mfi;      // MyClass<T, int>
    MyClass<float*, double*> mp;  // MyClass<T1*, T2*>
}
