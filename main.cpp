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
        while (current)
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

    return 0;
}
