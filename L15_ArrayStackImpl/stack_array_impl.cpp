#include "stack_array_impl.h"

StackArray::StackArray()
{
    m_top = -1;
}

StackArray::~StackArray()
{
}

void StackArray::Push(int x)
{
    if (m_top == MAX_SIZE - 1)
    {
        std::cout << "Error! Stack overflow, top: " << m_top << std::endl;
        return;
    }

    m_arr[++m_top] = x;
}

void StackArray::Pop()
{
    if (m_top == -1)
    {
        std::cout << "Error! Stack is already Empty" << std::endl;
        return;
    }

    m_top--;
}

int StackArray::Top()
{
    if (m_top == -1)
    {
        std::cout << "Error! Stack is already Empty" << std::endl;
        return -1;
    }
    return m_arr[m_top];
}

bool StackArray::IsEmpty()
{
    return (m_top == -1);
}

void StackArray::Print()
{
    std::cout << "Printing Stack: ";
    if (m_top == -1)
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        for (int i = 0; i <= m_top; i++)
        {
            std::cout << m_arr[i] << " ";
        }
        std::cout << std::endl;
    }
}
