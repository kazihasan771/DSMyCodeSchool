#pragma once
#include <iostream>
#include <string>

const int MAX_SIZE = 5;

class StackArray
{
private:
    int m_arr[MAX_SIZE];
    int m_top;

public:
    StackArray();
    ~StackArray();
    void Push(int x);
    void Pop();
    int Top();
    bool IsEmpty();
    void Print();
};
