#pragma once
// basic class template example - stack implementation

#include <deque>
#include <stdexcept>
#include <string>
#include <vector>

template<typename T>
class Stack {
public:
    void push(T const&);
    void pop();
    T top() const;

    bool empty() const
    {
        return elems.empty();
    }
private:
    std::vector<T> elems{};
};

template<typename T>
void Stack<T>::push(T const& elem)
{
    elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template<typename T>
T Stack<T>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}


// specialization

template<>
class Stack<std::string> {
public:
    void push(std::string const& elem);
    void pop();
    std::string top() const;

    bool empty() const
    {
        return elems.empty();
    }
private:
    std::deque<std::string> elems{};
};

void Stack<std::string>::push(std::string const& elem)
{
    elems.push_back(elem);
}

std::string Stack<std::string>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>::top(): empty stack");
    }
    return elems.back();
}

void Stack<std::string>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>::pop(): empty stack");
    }
    elems.pop_back();
}
