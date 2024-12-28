#include <iostream>
using namespace std;
struct Node
{
    int data;   // will hold any integer value
    Node *next; // will hold the address of the next value
};
Node *head = nullptr;              // head pointer is global and initialized to null
void append(Node *&head, const int data) // fn to append new node at the end
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
void delete_begin(Node *&head)  //fn to delete the first node
{
    if (head == nullptr)
    {
        cout << "List is empty\n"; // Head pointer is null mean no list is created
    }
    Node *temp = head; // copying the head node to a temporary node
    head = head->next; // shifting head to next node
    delete temp;       // deleting the first node
}

void delete_end(Node *&head)  //fn to delete the last node
{
    Node *temp = head; // storing head in temp pointer
    if (head == nullptr)
    {                                            // if there is no node
        cout << "List is Empty!!!" << endl;
    }
    if (head->next == nullptr)
    { // if there is one is node
        delete head;
        head = nullptr;
    }
    while (temp->next->next != nullptr)   // traversing to the second last node
    {
        temp = temp->next;           // moving to the next node
    }
    delete temp->next;            // deleting the last node
    temp->next = nullptr;   // setting null to secod last node
}

void traverse(Node *head) // function to traverse through each node
{
    Node *current = head;
    while (current)
    {
        cout << "[ " << current->data << " ] -> ";
        current = current->next;
    }
    cout << "None" << endl; // end of the list
}
int main() {
    int position,data,choice;
    do {
        cout << "----------Menu-------" << endl;    // Menu that showing option for user
        cout << "1. Insert at beginning"<< endl;
        cout << "2. Insert at end"<< endl;
        cout << "3. Insert at position"<< endl;
        cout << "4. Delete from beginning"<< endl;
        cout << "5. Delete from end"<< endl;
        cout << "6. Delete at position"<< endl;
        cout << "7. Delete by value"<< endl;
        cout << "8. Traverse"<< endl;
        cout << "9. Search"<< endl;
        cout << "10. Exit"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 2:
            cout << "Enter the value to be inserted: ";
            cin >> data;
            append(head, data);             // Calling append fn that add data in last in linked list
            break;
            case 4:
                delete_begin(head);        // Calling delete_begin fn that delete first node
            break;
            case 5:
                delete_end(head);          // Calling delete_end fn that delete last node
            break;
            case 8:
                traverse(head);               // Calling traverse fn that print linked list
            break;
            case 10:
                cout << "Exiting..." << endl; // Exiting from program
            cout<<"EXIT!!!"<<endl;
            exit(0);
            default:
                cout << "Invalid choice!!!" << endl; // if user input invalid option
        }
    }
        while (choice != 10);
    return 0;
}
