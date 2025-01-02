#include <iostream>
using namespace std;
struct Node
{
    int data;   // will hold any integer value
    Node *next; // will hold the address of the next value
};
int countNodes(Node *head) // fn to count amd return the number of nodes present in the list
{
    int count = 0;
    Node *current = head;
    while (current) // traversing till the end (including the last node itself)
    {
        current = current->next;
        count += 1;
    }

    return count;
}
Node *head = NULL; // head pointer is global and initialized to null
void insert_begin(Node *&head, const int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = head; // setting the next pointer of new node to the previous head of the list
    head = new_node;       // changing head to the newly added node
    cout << "Node succesfully added" << endl;
}
void insert_end(Node *&head, const int data) // fn to append new node at the end
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    if (head) // only true if node(s) already exist
    {
        Node *current = head;
        while (current->next) // traversing until we reach the node which has 'next' pointer pointing to nullptr
        {
            current = current->next;
        }
        current->next = new_node; // setting next of the older node to point to new node (which has it's next pointing to nullptr)
        cout << "Node successfully added" << endl;
    }
    else
    {
        head = new_node; // if list is empty, sets the head as the new node
        cout << "Node successfully added" << endl;
    }
}
void insert_at(Node *&head, const int data, const int pos) // fn to insert a new node at a specific position
{
    Node *new_node = new Node;
    new_node->data = data;
    Node *current = head;
    int length = countNodes(head); // stores the length of the current list
    if (pos >= length || pos < 0)  // if user gives a out of bound position
    {
        cout << "Position doesn't exist." << endl;
    }
    else if (pos == 0) // if pos == 0 (head)
    {
        new_node->next = head;
        head = new_node;
        cout << "Node successfully added at position " << pos << endl;
    }
    else // positions other than head
    {
        for (int i = 0; i < pos - 1; i++) // looping till we reach the node just before the position we want our new data to be inserted at
        {
            current = current->next; // Move to the next node
        }
        new_node->next = current->next; // pointing the new node to the node which is the next node of the current node
        current->next = new_node;       // setting the current node to point to the new node (which re-establishes the link after inserting)
        cout << "Node successfully added at position " << pos << endl;
    }
}
void delete_begin(Node *&head) // fn to delete the first node
{
    if (head == NULL)
    {
        cout << "List is empty" << endl; // Head pointer is null mean no list is created
        return;                          // should immediately exit this function once this case is handled, (list doesn't exist) so rest of the fn doesn't execute
    }

    Node *temp = head;                                  // copying the head node to a temporary node
    head = head->next;                                  // shifting head to next node
    delete temp;                                        // deleting the first node
    cout << "First node successfully deleted." << endl; // status message
}

void delete_at(Node *&head, const int pos) // fn to delete a node at a specific position
{
    Node *temp = head;
    int length = countNodes(head); // stores the length of the current list
    if (pos >= length || pos < 0)  // checks if pos is out of bounds
    {
        cout << "Position doesn't exist." << endl;
        return; // exits the loop immediately if pos is out of bounds
    }
    else if (head == NULL)
    {
        cout << "List is empty" << endl;
        return; // exits the loop immediately if the list is empty
    }
    if (pos == 0) // if user wants to del head
    {
        head = head->next;
        delete temp;
        cout << "Node successfully deleted at position " << pos << endl;
        return;
    }
    // traversing to the node just before the desired position
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *next = temp->next->next; // setting next pointer to point to the node after the node user want to delete
    delete temp->next;             // deleting the node
    temp->next = next;             // setting the next of the temp node (the node just before the desired node) to the node which is after the node which user deleted
    cout << "Node successfully deleted at position " << pos << endl;
}
void delete_data(Node *&head, int data) // fn to delete node with a specific data
{
    if (head == NULL)
    { // if list is empty
        cout << "List is empty" << endl;
        return; // Exit the function
    }
    if (head->data == data)
    {                      // if data is present on first node
        Node *temp = head; // Save the first node
        head = head->next; // Move to next node
        delete temp;       // delete the first node
        cout << "Node with value = " << data << " Deleted." << endl;
        return; // Exit the function
    }
    Node *current = head;
    while (current)
    { // Traversing list till END / Searching in List
        if (current->next->data == data)
        {                               // Check if the data in the next node matches the value to be deleted
            Node *temp = current->next; // Save the node to be deleted
            current->next = temp->next; // Bypass to next node without disconnecting list
            delete temp;                // Free Memory / Deleting Memory
            cout << "Node with value = " << data << " Deleted." << endl;
            return; // Exit the function
        }
        current = current->next; // Move to next node
    }
    cout << "Node with value = " << data << " Not Found" << endl;
}
void delete_end(Node *&head) // fn to delete the last node
{
    Node *temp = head; // storing head in temp pointer
    if (head == NULL)
    { // if there is no node
        cout << "List is Empty." << endl;
        return; // should immediately exit this function once this case is handled, (list doesn't exist) so rest of the fn doesn't execute
    }
    if (head->next == NULL)
    { // if there is one is node
        delete head;
        head = NULL;
        cout << "Last node successfully deleted." << endl;
        return; // should immediately exit this function once this case is handled, (only one node exists) so rest of the fn doesn't execute
    }
    while (temp->next->next != NULL) // traversing to the second last node
    {
        temp = temp->next; // moving to the next node
    }
    delete temp->next; // deleting the last node
    temp->next = NULL; // setting null to secod last node
    cout << "Last node successfully deleted." << endl;
    // doesn't require a return as there isn't any code after this case (more than one node) anyways
}
Node *search(Node *head, const int data)
{ // fn to search/traverse until the desired node is found -> returns the pointer of that node
    Node *current = head;
    while (current) // traversing
    {
        if (current->data == data)
        {
            return current; // exits the loop with the pointer of the found node
        }
        current = current->next;
    }
    return NULL; // if node not found
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
int main()
{
    int position, data, choice;
    Node *result;
    do
    {
        cout << "----------Menu-------" << endl; // Menu that showing option for user
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Delete by value" << endl;
        cout << "8. Traverse" << endl;
        cout << "9. Search" << endl;
        cout << "10. Count Nodes" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> data;
            insert_begin(head, data);
            break;
        case 2:
            cout << "Enter the value to be inserted: ";
            cin >> data;
            insert_end(head, data); // Calling append fn that add data in last in linked list
            break;
        case 3:
            cout << "Enter the value to be inserted: ";
            cin >> data;

            cout << "Enter the position you want to insert at (indexing starts from 0): ";
            cin >> position;

            insert_at(head, data, position);
            break;
        case 4:
            delete_begin(head); // Calling delete_begin fn that delete first node
            break;
        case 5:
            delete_end(head); // Calling delete_end fn that delete last node
            break;
        case 6:
            cout << "Enter the position you want to delete (indexing starts from 0): ";
            cin >> position;
            delete_at(head, position); // Calling delete_at fn that delete node at specific position
            break;
        case 7:
            cout << "Enter the data you want to delete: ";
            cin >> data;
            delete_data(head, data);
            break;
        case 8:
            if (head == NULL)
            {
                cout << "List doesn't exist." << endl;
            }
            else
            {
                traverse(head); // Calling traverse fn that print linked list
            }
            break;
        case 9:
            cout << "Enter the data you want to search: ";
            cin >> data;
            result = search(head, data); // will either have pointer or NULL stored in result
            if (result)
            {
                cout << result->data << " found at position " << result << endl;
            }
            else
            {
                cout << data << " not found." << endl;
            }
            break;
        case 10:
            cout << "There are " << countNodes(head) << " elements in your list." << endl;
            break;
        case 11:
            cout << "Exiting..." << endl; // Exiting from program
            exit(0);
        default:
            cout << "Invalid choice." << endl; // if user input invalid option
        }
    } while (choice != 11);
    return 0;
}
