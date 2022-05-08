#include "Stack.h"

Stack::Stack() {
    this->list = new LinkedList();
}

Stack::~Stack() {
    if (list != nullptr) {
        delete this->list;
    }
}

void Stack::push(int data) {
    list->insertAtHead(data);
}

void Stack::pop() {
    if (!isEmpty()) {
        list->deleteHead();
    }
}

int Stack::top() {
    if (!isEmpty()) {
        return list->head->data;
    }
    return -1;
}

bool Stack::isEmpty() {
    return (list->head == nullptr);
}

void Stack::print() {
    list->printList();
}