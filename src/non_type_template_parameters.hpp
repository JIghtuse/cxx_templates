#pragma once

#include <stdexcept>
#include <array>

template<typename T, size_t MaxSize>
class Stack {
public:
    void push(const T& elem);
    void pop();
    T top() const;

    bool empty() const {
        return size == 0;
    }

    bool full() const {
        return size == MaxSize;
    }
private:
    std::array<T, MaxSize> elems{};
    size_t size{};
};

template<typename T, size_t MaxSize>
void Stack<T, MaxSize>::push(const T& elem)
{
    if (size >= MaxSize) {
        throw std::out_of_range("Stack<>::push(): stack is full");
    }
    elems[size] = elem;
    ++size;
}

template<typename T, size_t MaxSize>
void Stack<T, MaxSize>::pop()
{
    if (size == 0) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    --size;
}

template<typename T, size_t MaxSize>
T Stack<T, MaxSize>::top() const
{
    if (size == 0) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems[size - 1];
}
