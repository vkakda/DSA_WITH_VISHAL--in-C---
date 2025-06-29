//  DSA With Vishal - Doubly Linked List

/*
    Implementation of a Doubly Linked List in C++.

    This code defines a Node class for doubly-linked list nodes and a DoublyList class
    that supports insertion at the front and back (push_front, push_back), deletion from
    the front and back (pop_front, pop_back), and printing the list. The main function
    demonstrates usage by inserting and removing elements, then printing the list.
*/


#include <iostream>
using namespace std;

// Definition for doubly-linked list node.
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    //push_front 
    void push_front (int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    //push_back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //pop_front
    void pop_front() {
        if (head == NULL) {
            cout << "List is empty, nothing to pop." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if( head != NULL){
            head->prev = NULL;
        }
       temp->next = NULL;
       delete temp;
    }

    //pop_back
    void pop_back() {
        if (tail == NULL) {
            cout << "List is empty, nothing to pop." << endl;
            return;
        }
        Node* temp =  tail;
        tail = tail->prev;
        if(tail != NULL){
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
        }

    //print function
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};



int main() {
   DoublyLinkedList dll;

    // dll.push_front(1);
    // dll.push_front(2);
    // dll.push_front(3);

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);

    // dll.pop_front();
    dll.pop_back();

    dll.print(); 


    return 0;
}

