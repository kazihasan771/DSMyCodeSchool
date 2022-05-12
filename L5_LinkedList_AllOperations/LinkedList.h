#pragma once

#include "Node.h"

class LinkedList
{
private:
    Node *m_head;

public:
    LinkedList();
    ~LinkedList();

    // Inserts
    void insertAthead(int data);
    void insertAtPosition(int position, int data);
    void insertAtEnd(int data);
    // Deletes
    void deleteFromHead();
    void deleteFromEnd();
    void deleteFromPosition(int position);

    // Reverses
    void reverseIterative();
    void reverseUsingStack();
    //  Misc
    void print();
};
