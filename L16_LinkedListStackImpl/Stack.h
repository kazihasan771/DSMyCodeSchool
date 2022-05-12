#pragma once
#include "LinkedList.h"

class Stack {
    LinkedList* list;

public:
    Stack();
    ~Stack();

    void push(int data);
    void pop();
    int top();
    bool isEmpty();
    void print();
};