/*
    DSA With Vishal - Circular Linked List

    Implementation of a Circular Linked List in C++.

    This code defines a Node class for circular linked list nodes and a CircularLinkedList class
    that supports insertion at the front and back (push_front, push_back), deletion from
    the front and back (pop_front, pop_back), and printing the list. The main function
    demonstrates usage by inserting and removing elements, then printing the list.
*/

#include <iostream>
using namespace std;

// Definition for circular linked list node.
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = tail = NULL;
    }

    //insert at Head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    //insert at Tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //Delete at Head
    void deleteAtHead() {
        if ( head == NULL) return;  
        else if (head == tail) { // single node case
            delete head;
            head = tail = NULL;
        } else {                 // 2 or more nodes
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }   
    }

    //Delete at Tail
    void deleteAtTail() {
         if ( head == NULL) return;  
        else if (head == tail) { // single node case
            delete head;
            head = tail = NULL;
        } else {                 // 2 or more nodes
            Node* temp = tail;
            Node* prev = head;
            while (prev->next != tail) {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }   
    }

    // print function
    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        cout << head->data << " -> ";
        Node* temp = head->next;
        while (temp != head) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data <<"(Head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cll.print();


    cll.deleteAtHead();
    cll.deleteAtTail();

    cll.print();

    return 0;
}