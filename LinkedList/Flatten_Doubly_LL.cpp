// DSA With Vishal - Flatten a Multilevel Doubly Linked List

// Problem Statement:
// You are given the head of a doubly linked list, where in addition to the next and previous pointers, 
// each node has a child pointer, which may or may not point to a separate doubly linked list. 
// These child lists may have one or more children of their own, and so on, to produce a multilevel data structure.
// Flatten the list so that all the nodes appear in a single-level, doubly linked list. 
// You must do it in place, so that the original nodes are rearranged.

// Approach:
// We traverse the list, and whenever we find a node with a child, we recursively flatten the child list 
// and insert it between the current node and the next node. We continue this process until the entire list is flattened.

// Example:
// Input: 1 - 2 - 3 - 4 - 5 - 6
//                 |
//                 7 - 8 - 9 - 10
//                     |
//                     11 - 12
// Output: 1-2-3-7-8-11-12-9-10-4-5-6

// Time Complexity: O(n), where n is the total number of nodes in all levels.
// Space Complexity: O(1) (excluding recursion stack).

#include <iostream>
using namespace std;

// Definition for a Node in a doubly linked list.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int x) : val(x), prev(NULL), next(NULL), child(NULL) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* child = flatten(curr->child);
                Node* next = curr->next;

                // Connect curr and child
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                // Find the tail of the child list
                Node* tail = child;
                while (tail->next) tail = tail->next;

                // Connect tail and next
                tail->next = next;
                if (next) next->prev = tail;
            }
            curr = curr->next;
        }
        return head;
    }
};

// Print the doubly linked list from a given node
void printList(Node* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage
    // Creating the multilevel doubly linked list as per the example
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    // Level 2
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    head->next->next->child = node7;
    node7->next = node8;
    node8->prev = node7;
    node8->next = node9;
    node9->prev = node8;
    node9->next = node10;
    node10->prev = node9;

    // Level 3
    Node* node11 = new Node(11);
    Node* node12 = new Node(12);
    node8->child = node11;
    node11->next = node12;
    node12->prev = node11;

    cout << "Original List (flattened view): ";
    printList(head); // This will only print the top level

    Solution s;
    Node* flat = s.flatten(head);

    cout << "Flattened List: ";
    printList(flat);

    return 0;
}

// LeetCode Problem: 430 // https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                // Connect curr and child
                curr->next->prev = curr;
                curr->child = NULL;

                // Find the tail of the child list
                while (curr->next != NULL) {
                 curr = curr->next;
                }

                // Connect with next
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
    
};  */