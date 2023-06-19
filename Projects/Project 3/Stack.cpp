// Copyright 2022 - Samson Huang
// Email: shuang18@mail.sfsu.edu
// CSC340.02 - Spring 2022 
// This file is part of CSC 340 - Assignment 3.1

#include <iostream>
#include "Stack.h"
#include "StackInterface.h"

using namespace std;

template <class Item>
Stack<Item>::Stack(){}

template <class Item>
bool Stack<Item>::push(const Item& newItem){
    items[++top] = newItem;
    return true;
}

template <class Item>
bool Stack<Item>::pop(){
    if(!isEmpty()){
        top--;
        return true;
    } else{
        return false;
    }
}

template <class Item>
Item Stack<Item>::peek() const{
    if(!isEmpty()){
        return top;
    } else{
        exit(EXIT_FAILURE);
    }
}

template <class Item>
bool Stack<Item>::isEmpty() const{
    top == -1;
    return top;
}

template <class Item>
bool Stack<Item>::isFull() const{
    top == items * 2;
    return top;
}
