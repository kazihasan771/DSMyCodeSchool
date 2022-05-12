#pragma once

class Node
{
public:
    int m_data;
    Node *m_next;
    Node();
    Node(int data);
    ~Node();
};