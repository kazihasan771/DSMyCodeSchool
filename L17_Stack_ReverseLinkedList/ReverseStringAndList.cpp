// #include "LinkedList.h"
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

void reverseStringwithStack(char c[], int n)
{
    std::stack<char> s;

    // Loop for pushing chars to stack from left to right
    for (int i = 0; i < n; i++)
    {
        s.push(c[i]);
    }

    // Loop for Popping chars
    for (int i = 0; i < n; i++)
    {
        c[i] = s.top(); // Overwrite the chars at index i
        s.pop();
    }
}

void reverseStringIterative(char c[], int n)
{
    int start = 0;
    int end = n - 1;
    char temp;
    while (start < end)
    {
        temp = c[start];
        c[start] = c[end];
        c[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    std::cout << "Reverse String with Iterative approach" << std::endl;
    char string[8] = "Hello";
    reverseStringIterative(string, strlen(string));
    std::cout << string << std::endl;
}