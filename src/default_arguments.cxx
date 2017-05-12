#include "default_arguments.hpp"
#include <iostream>
#include <deque>

int main()
{
    try {
        // std::vector<int> will be used to store elements
        auto intStack = Stack<int>{};

        // std::deque<double> will be used to store elements
        auto doubleStack = Stack<double, std::deque<double>>{};

        intStack.push(7);
        std::cout << intStack.top() << '\n';

        doubleStack.push(42.42);
        std::cout << doubleStack.top() << '\n';
        doubleStack.pop();
        doubleStack.pop();

    } catch (std::exception const& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
}
