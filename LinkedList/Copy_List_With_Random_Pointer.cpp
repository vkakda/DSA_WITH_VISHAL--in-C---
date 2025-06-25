// DSA With Vishal - Copy List With Random Pointer

// Problem Statement:
// A linked list is given where each Node contains an additional random pointer, which could point to any Node in the list or null.
// Return a deep copy of the list.

// Approach:
// 1. Insert cloned Nodes in between original Nodes.
// 2. Set random pointers for the cloned Nodes.
// 3. Separate the cloned list from the original list.

// Example:
// Input: 1 -> 2 -> 3 -> NULL, with random pointers
// Output: Deep copy of the list with correct next and random pointers

// Time Complexity: O(n), where n is the number of Nodes in the list.
// Space Complexity: O(1), as we do not use extra space for mapping.

// LeetCode Problem: 138 // https://leetcode.com/problems/copy-list-with-random-pointer/

#include <iostream>
#include <unordered_map>
using namespace std;

// Type aliases to match the Solution class usage

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead; // Map original Node to new Node

        while(oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode; // Map old Node to new Node
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head; newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random]; // Set random pointers
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;       
    }

        return newHead; // Return the head of the cloned list
    }
};


// Print the linked list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Value: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}
// Example usage
Node* createSampleList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    head->random = third; // 1's random points to 3
    second->random = head; // 2's random points to 1
    third->random = second; // 3's random points to 2

    return head;
}   

int main() {
    Node* head = createSampleList();
    cout << "Original List:\n";
    printList(head);

    Solution solution;
    Node* clonedHead = solution.copyRandomList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    // Clean up memory (not shown here, but should be done in practice)
    
    return 0;
}