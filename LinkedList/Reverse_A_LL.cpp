// DSA With Vishal- Reverse a Linked List


// Problem Statement:
// Given the head of a singly linked list, reverse the list and return the new head.

// Approach:
// Iterate through the linked list, reversing the next pointers as you go.

// Example:
// Input: 1 -> 2 -> 3 -> 4 -> NULL
// Output: 4 -> 3 -> 2 -> 1 -> NULL

// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), as we reverse the list in place.

#include <iostream>
using namespace std;

//printing the linked list
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer

            prev = curr;       // Move prev to current node
            curr = next;       // Move to the next node
        }

        return prev; // New head of the reversed list
    }
};

//print function for linked list
void printList(ListNode* head) {
    cout << "Original List: ";

    while(head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//print reverse linked list
void printReverseList(ListNode* head) {
    cout << "Reversed List: ";
    string result = "";
    while (head != NULL) {
        result = "<-" + to_string(head->val) + result;
        head = head->next;
    }
    cout << "NULL" << result << endl;
}


int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    printList(head);

    Solution s;
    ListNode* reversedHead = s.reverseList(head);

    printReverseList(reversedHead);


    return 0;
}

// LeetCode Problem: 206 // https://leetcode.com/problems/reverse-linked-list/