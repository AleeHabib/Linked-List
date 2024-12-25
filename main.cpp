#include <iostream>
using namespace std;
struct Node
{
    int data;   // will hold any integer value
    Node *next; // will hold the address of the next value
};
void append(Node *&head, int data) // function to append new node at the end
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (head) // only true if node(s) already exist
    {
        Node *current = head;
        while (current->next) // traversing until we reach the node which has 'next' pointer pointing to nullptr
        {
            current = current->next;
        }
        current->next = new_node; // setting next of the older node to point to new node (which has it's next pointing to nullptr)
    }
    else
    {
        head = new_node; // if list is empty, sets the head as the new node
    }
}
void traverse(Node *head) // function to traverse through each node
{
    Node *current = head;
    while (current)
    {
        cout << "[ " << current->data << " ] -> ";
        current = current->next;
    }
    cout << "None"; // end of the list
}
int main()
{
    Node *head = nullptr; // Starting with an empty list

    append(head, 1);
    append(head, -3);
    append(head, 7);

    traverse(head);
    return 0;
}
