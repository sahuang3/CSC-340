// This file is part of CSC 340 - Assignment 3.1

#ifndef STACK_
#define STACK_
#include "StackInterface.h"
using namespace std;

template<class Item>
class Stack : public StackInterface<Item>{
private:
    static const int DEFAULT_SIZE = 6;
    Item items[DEFAULT_SIZE];
    int top;
public:
    Stack();
    bool push(const Item& items);
    bool pop();
    Item peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

#include "Stack.cpp"
#endif
