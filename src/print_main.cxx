#include "print.h"
#include <iostream>

int main()
{
    int numbers[] = {3, 1, 4, 5, 9, 2, 6, 5, 3, 5};

    print(numbers);
    std::cout << '\n';

    print(numbers, "{", ",", "}\n");
}
