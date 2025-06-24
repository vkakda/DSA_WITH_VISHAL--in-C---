/* DSA With Vishal- Introduction to Linked List
   This code demonstrates basic operations on a singly linked list in C++.
   Operations include push_front, push_back, pop_front, pop_back, insert_middle,
   search, and printLL.
*/


#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node* head;
    Node* tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // Push at front
    void push_front(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == NULL)
            tail = newNode;
    }

    // Push at back
    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // Pop from front
    void pop_front()
    {
        if (!head)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
            tail = NULL;
    }

    // Pop from back
    void pop_back()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail)
            temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // Insert at position (0-based index)
    void insert_middle(int pos, int val)
    {
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; ++i)
            temp = temp->next;
        if (!temp)
            return; // Position out of bounds
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
            tail = newNode;
    }

    // Search for a value
    bool search(int key)
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Print the linked list
    void printLL()
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~List()
    {
        while (head)
            pop_front();
    }
};

// Push at front
void push_front(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Push at back
void push_back(Node* &head, int val)
{
    Node* newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Pop from front
void pop_front(Node* &head)
{
    if (!head)
        return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Pop from back
void pop_back(Node* &head)
{
    if (!head)
        return;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

// Insert at position (0-based index)
void insert_middle(Node* &head, int pos, int val)
{
    if (pos == 0)
    {
        push_front(head, val);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; ++i)
        temp = temp->next;
    if (!temp)
        return; // Position out of bounds
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Search for a value
bool search(Node* head, int key)
{
    Node* temp = head;
    while (temp)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// Print the linked list
void printLL(Node* head)
{
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Example usage
int main()
{
    Node* head = NULL;
    push_front(head, 10);
    push_back(head, 20);
    push_front(head, 5);
    insert_middle(head, 1, 15); // Insert 15 at position 1
    printLL(head);

    pop_front(head);
    printLL(head);

    pop_back(head);
    printLL(head);

    cout << "Search 15: " << (search(head, 15) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (search(head, 100) ? "Found" : "Not Found") << endl;

    // Free memory
    while (head)
        pop_front(head);

    return 0;
}