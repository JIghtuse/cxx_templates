// Using class template example
#include "stack.hpp"
#include <iostream>
#include <string>

using IntStack = Stack<int>;

int main()
{
    try {
        auto intStack = IntStack{};
        auto stringStack = Stack<std::string>{};

        intStack.push(7);
        std::cout << intStack.top() << '\n';
        // intStack.pop() was not instantiated, because it is not used

        stringStack.push("hello");
        std::cout << stringStack.top() << '\n';
        stringStack.pop();
        stringStack.pop();

        // it is possible to use instantiated class template as any other type
        IntStack istack[10];
        auto intStackStack = Stack<Stack<int>>{};
    } catch (std::exception const& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
}
