#include "Stack.h"
#include <iostream>

int main()
{
    std::cout << "Stack Using LinkedList" << std::endl;
    Stack myStack;

    myStack.print();

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(25);
    myStack.print();

    myStack.pop();
    std::cout << "Top of stack is: " << myStack.top() << std::endl;

    myStack.pop();
    myStack.print();

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.print();

    myStack.pop();
    myStack.print();

    return 0;
}