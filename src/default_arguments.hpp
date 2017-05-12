#pragma once

#include <stdexcept>
#include <vector>

template<typename T, typename Container = std::vector<T>>
class Stack {
public:
    void push(T const&);
    void pop();
    T top() const;

    bool empty() const {
        return elems.empty();
    }
private:
    Container elems{};
};


template<typename T, typename Container>
void Stack<T, Container>::push(T const& elem)
{
    elems.push_back(elem);
}

template<typename T, typename Container>
void Stack<T, Container>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>::pop(): empty stack");
    }
    elems.pop_back();
}

template<typename T, typename Container>
T Stack<T, Container>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>::pop(): empty stack");
    }
    return elems.back();
}
