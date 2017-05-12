#include "non_type_template_parameters.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

// Using non-type template parameter for function template
template<typename T, int Val>
T addValue(T const& x)
{
    return x + Val;
}

int main()
{
    try {
        auto int20Stack = Stack<int, 20>{};
        int20Stack.push(7);
        std::cout << int20Stack.top() << '\n';
        int20Stack.pop();

        auto int40Stack = Stack<int, 40>{};
        int40Stack.push(5);

        auto numbers = std::vector<int>(5);
        std::transform(numbers.begin(), numbers.end(),
                       numbers.begin(),
                       addValue<int, 42>);
        std::cout << numbers.front() << '\n';

        auto stringStack = Stack<std::string, 4>{};
        for (auto i = 0; i < 5; ++i) {
            stringStack.push("hi");
            std::cout << stringStack.top() << '\n';
        }
    } catch (std::exception const& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
}
