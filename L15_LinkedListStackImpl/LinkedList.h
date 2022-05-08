#pragma once
#include "Node.h"

class LinkedList {
    int length;
    
    public:
        Node* head;
        LinkedList();
        ~LinkedList();

        void insert(int data);
        void insertAt(int data, int position);
        void insertAtHead(int data);
                
        void deleteTail();
        void deleteNodeAt(int position);
        void deleteHead();

        void reverseList();
        void reverseListRec(Node* tempHead);
        Node* nonVoidReverseListRec(Node* tempHead, Node* nextNode);
        void printList();
        void printListRec(Node* tempHead);
        void printListInReverseRec(Node* tempHead);
};