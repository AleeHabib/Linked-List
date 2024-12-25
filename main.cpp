#include <iostream>
using namespace std;
struct Node
{
    int data;   // will hold any integer value
    Node *next; // will hold the address of the next value
};
void append(Node *&head, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (head)
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    else
    {
        head = new_node;
    }
}
int main()
{
    Node *head = nullptr; // Starting with an empty list

    // append(head, 1);
    // append(head, 2);
    // append(head, 3);

    // Output the list
    Node *current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "None";
    return 0;
}
