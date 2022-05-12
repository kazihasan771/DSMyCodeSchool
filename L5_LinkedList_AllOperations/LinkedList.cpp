#include "LinkedList.h"
#include <iostream>
#include <stack>

LinkedList::LinkedList()
{
    m_head = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::insertAthead(int data)
{
    Node *newNode = new Node(data);
    newNode->m_next = m_head;
    m_head = newNode;
}

void LinkedList::insertAtEnd(int data)
{
    Node *temp = m_head;
    if (temp == nullptr)
    {
        std::cout << "Empty List, Inserting at Head" << std::endl;
        insertAthead(data);
        return;
    }
    while (temp->m_next != nullptr)
    {
        temp = temp->m_next;
    }
    Node *newNode = new Node(data);
    temp->m_next = newNode;
}

void LinkedList::insertAtPosition(int position, int data)
{
    // Head(first node) position is 1
    if (position <= 0)
    {
        std::cout << "Error! Invalid position for Inserting Node" << std::endl;
        return;
    }

    Node *newNode = new Node(data);
    // For position = 1, we are basically performing an insert at head
    if (position == 1)
    {
        newNode->m_next = m_head;
        m_head = newNode;
        return;
    }

    Node *curr = m_head;
    // If we want to insert at position "n", we need to traverse to position "n-1"
    for (int i = 1; i < position - 1; i++)
    {
        if (curr->m_next != nullptr)
        {
            curr = curr->m_next;
        }
        else
        {
            std::cout << "Error! Reached null ptr but position is not valid: " << std::endl;
            return;
        }
        std::cout << "Loooping: " << i << " ,curr->data: " << curr->m_data << std::endl;
    }
    std::cout << "Looop ended." << std::endl;
    // Now Curr points to "n-1" node
    newNode->m_next = curr->m_next;
    curr->m_next = newNode;
}

void LinkedList::deleteFromHead()
{
    if (m_head == nullptr)
    {
        std::cout << "List is empty, cannot delete " << std::endl;
        return;
    }

    Node *temp = m_head;
    m_head = temp->m_next;
    delete temp;
}

void LinkedList::deleteFromEnd()
{
    if (m_head == nullptr)
    {
        std::cout << "List is empty, cannot delete " << std::endl;
        return;
    }
    Node *curr = m_head;
    if (curr->m_next == nullptr)
    {
        m_head = curr->m_next;
    }
    else
    {
        Node *prev;
        while (curr->m_next != nullptr)
        {
            prev = curr;
            curr = curr->m_next;
        }
        prev->m_next = nullptr;
    }

    delete curr;
}

void LinkedList::deleteFromPosition(int position)
{
    if (position <= 0)
    {
        std::cout << "Error! Invalid position for Deleting Node" << std::endl;
        return;
    }

    Node *curr = m_head;

    // Deleting the first node
    if (position == 1)
    {
        m_head = curr->m_next;
    }
    else
    {
        Node *prev;
        for (int i = 1; i < position; i++)
        {
            prev = curr;
            curr = curr->m_next;
        }
        prev->m_next = curr->m_next;
    }
    delete curr;
}

void LinkedList::reverseIterative()
{
    if (m_head == nullptr)
    {
        std::cout << " List is empty, cannot reverse." << std::endl;
        return;
    }

    Node *curr = m_head;
    Node *prev = curr;
    Node *next = nullptr;
    prev->m_next = nullptr;
    while (curr->m_next != nullptr)
    {
        prev = curr;
        std::cout << "Reverse: prev: " << prev->m_data << std::endl;
        curr = curr->m_next;
        std::cout << "Reverse: curr: " << curr->m_data << std::endl;
        next = curr;
        std::cout << "Reverse: next: " << next->m_data << std::endl;
        next->m_next = prev;
    }
    m_head = curr;
}

void LinkedList::reverseUsingStack()
{
    if (m_head == nullptr)
    {
        std::cout << "List is empty, cannot reverse" << std::endl;
        return;
    }

    std::stack<Node *> s;
    Node *curr = m_head;
    while (curr->m_next != nullptr)
    {
        s.push(curr);
        curr = curr->m_next;
    }
    m_head = curr;
    while (!s.empty())
    {
        curr->m_next = s.top();
        curr = s.top();
        s.pop();
    }
    curr->m_next = nullptr;
}

void LinkedList::print()
{
    Node *temp = m_head;
    if (temp == nullptr)
    {
        std::cout << "List is Empty" << std::endl;
        return;
    }

    std::cout << "Current List: ";
    while (temp != nullptr)
    {
        std::cout << temp->m_data << " ";
        temp = temp->m_next;
    }
    std::cout << std::endl;
}