#include <iostream>
#include "LinkedList.h"

int main()
{
    std::cout << "LinkedList Implementation" << std::endl;
    LinkedList list;
    list.print();
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAthead(1);
    list.insertAtPosition(4, 4);

    list.insertAtPosition(5, 5);
    list.insertAtPosition(6, 6);

    list.print();
    list.reverseUsingStack();
    list.print();

    // list.reverseIterative();
    // list.print();
    // list.deleteFromHead();
    // list.print();
    // list.deleteFromEnd();
    // list.print();
    // list.deleteFromPosition(3);
    // list.print();
    // list.deleteFromPosition(3);
    // list.print();

    std::cout << "End of LinkedList Implementation" << std::endl;

    // list.deleteFromPosition(2);
    // list.print();

    return 0;
}