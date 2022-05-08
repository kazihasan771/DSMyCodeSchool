#include "stack_array_impl.h"

int main()
{
    std::cout << "Stack Using Array" << std::endl;
    StackArray s;
    s.Print();
    s.Top();
    s.Pop();
    s.Push(2);
    s.Push(7);
    s.Push(5);
    s.Print();
    std::cout << "Current top is: " << s.Top() << std::endl;
    s.Pop();
    s.Print();
    std::cout << "Current top is: " << s.Top() << std::endl;
    s.Push(8);
    s.Push(9);
    s.Push(10);
    s.Print();
    std::cout << "Current top is: " << s.Top() << std::endl;
    s.Push(11);
    s.Print();
    std::cout << "Current top is: " << s.Top() << std::endl;

    s.Pop();
    s.Push(33);
    s.Print();
    std::cout << "Current top is: " << s.Top() << std::endl;

    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();

    s.Print();
    std::cout << "Current top is: " << s.Top() << std::endl;

    return 0;
}