#include "LinkedList.h"
#include <iostream>
#include <stack>

void LinkedList::reverseUsingStack()
{
    if (m_head == nullptr)
    {
        std::cout << "List is empty, cannot reverse" << std::endl;
        return;
    }

    std::stack<Node *> s;
    Node *curr = m_head;
    // First loop: Push all but last node in the stack
    while (curr->m_next != nullptr)
    {
        s.push(curr);
        curr = curr->m_next;
    }
    // Curr now points to last node, set it to head to start reversal
    m_head = curr;

    // Second Loop: Until loop is empty, reverse the next links for all but first node
    while (!s.empty())
    {
        // Top of the stack now points to previous node
        curr->m_next = s.top();
        curr = s.top();
        s.pop();
    }
    // Finally, set the last node's next link to nullPtr
    curr->m_next = nullptr;
}
