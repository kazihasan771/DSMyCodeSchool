#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
    head = nullptr;
    length = 0;
}

LinkedList::~LinkedList()
{
    Node *temp = head;
    Node *nodeToDelete = temp;
    while (temp != nullptr)
    {
        temp = temp->next;
        // std::cout << "Removing node: " << nodeToDelete->data << std::endl;
        delete nodeToDelete;
        nodeToDelete = temp;
    }
    head = nullptr;
}

// Function to insert new node at the end of the list
void LinkedList::insert(int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    length++;
}

// Function to insert new node at the beginning of the list
void LinkedList::insertAtHead(int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    length++;
}

// Function to insert new node at the nth position of the list, 1 being the first position
void LinkedList::insertAt(int data, int position)
{
    if (position < 1)
    {
        std::cerr << position << ": is not a valid position, it needs to be >= 1" << std::endl;
        return;
    }
    if (position > length + 1)
    {
        std::cerr << position << ": is not a valid position, as the current length is " << length << std::endl;
        return;
    }

    if (head == nullptr || position == 1)
    {
        insertAtHead(data);
        return;
    }
    else
    {
        Node *newNode = new Node(data);

        Node *temp = head;
        int i = 1;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    length++;
}

// Function to remove 1st node from linked list
void LinkedList::deleteHead()
{
    if (head == nullptr)
    {
        std::cout << "Can not delete, list is empty" << std::endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    length--;
}

// Function to remove last node from linked list
void LinkedList::deleteTail()
{
    if (head == nullptr)
    {
        std::cout << "Can not delete, list is empty" << std::endl;
        return;
    }
    // If there is only 1 element, head == tail
    if (length == 1)
    {
        deleteHead();
        return;
    }

    Node *temp = head;
    Node *previous_node = nullptr;
    while (temp->next != nullptr)
    {
        previous_node = temp;
        temp = temp->next;
    }

    previous_node->next = temp->next;
    delete temp;
    length--;
}

// Function to remove nth node from linked list, n starting from 1
void LinkedList::deleteNodeAt(int position)
{
    if (head == nullptr)
    {
        std::cout << "Can not delete, list is empty" << std::endl;
        return;
    }
    if (position < 1)
    {
        std::cerr << position << ": is not a valid position, it needs to be >= 1" << std::endl;
        return;
    }
    if (position > length)
    {
        std::cerr << position << ": is not a valid position, as the current length is " << length << std::endl;
        return;
    }
    if (position == 1)
    {
        deleteHead();
        return;
    }
    if (position == length)
    {
        deleteTail();
        return;
    }

    Node *temp = head;
    Node *previous_node = nullptr;
    int i = 1;
    while (i < position)
    {
        previous_node = temp;
        temp = temp->next;
        i++;
    }
    previous_node->next = temp->next;
    delete temp;
    length--;
}

// Function to reverse the linked list
void LinkedList::reverseList()
{
    if (head == nullptr)
    {
        std::cout << "List is empty, nothing to reverse" << std::endl;
        return;
    }
    Node *current_node = head;
    Node *previous_node = nullptr;
    Node *next_node = nullptr;

    while (current_node != nullptr)
    {
        // Save the location of next node
        next_node = current_node->next;
        // Set the new location of current_node->next to point to the previous node
        current_node->next = previous_node;

        // All set for current node, now update previous node
        previous_node = current_node;
        // Then update current node, so we can move forward
        current_node = next_node;
    }
    head = previous_node;
}

// Function to reverse the linked list, but recursively
void LinkedList::reverseListRec(Node *tempHead)
{
    if (tempHead->next == nullptr)
    {
        head = tempHead;
        return;
    }
    reverseListRec(tempHead->next);
    tempHead->next->next = tempHead;
    tempHead->next = nullptr;
}

// Non-void function to reverse the linked list, but recursively
Node *LinkedList::nonVoidReverseListRec(Node *tempHead, Node *nextNode = nullptr)
{
    if (tempHead->next == nullptr)
    {
        tempHead->next = nextNode;
        return tempHead;
    }

    Node *temp = tempHead->next;
    tempHead->next = nextNode;
    nonVoidReverseListRec(temp, tempHead);
}

// Function to print the linked list
void LinkedList::printList()
{
    if (head == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node *temp = head;
    std::cout << "The list: ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to print the linked list recursively
void LinkedList::printListRec(Node *tempHead)
{
    if (tempHead == nullptr)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << tempHead->data << " ";
    printListRec(tempHead->next);
}

// Function to print the linked list recursively in reverse order
void LinkedList::printListInReverseRec(Node *tempHead)
{
    static int count = 0;
    if (tempHead == nullptr)
    {
        return;
    }
    count++;
    printListInReverseRec(tempHead->next);
    std::cout << tempHead->data << " ";
    count--;
    if (count == 0)
    {
        std::cout << std::endl;
    }
}
