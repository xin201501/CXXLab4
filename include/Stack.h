#pragma once
#include <stdexcept>
#include <utility>
template<typename T>
class Stack {
public:
    Stack() : stack(new T[SIZE]), tos(-1) {}
    ~Stack() {
        delete[] stack;
    }
    void Push(T &n) {
        if (tos == SIZE-1) {
            throw std::runtime_error("stack is full!");
        }
        stack[++tos] = n;
    }
    T Pop() {
        if (tos == -1) {
            throw std::runtime_error("stack is empty!");
        }
        return stack[tos--];
    }

private:
    static const int SIZE;
    T *stack;
    int tos;
};
template<typename T>
const int Stack<T>::SIZE = 10;