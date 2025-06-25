// DSA With Vishal - Middle of a Linked List

// Problem Statement:
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Approach:
// Use two pointers (slow and fast). Move slow by one step and fast by two steps.
// When fast reaches the end, slow will be at the middle.

// Example:
// Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// Output: 3 -> 4 -> 5 -> NULL

// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), as we use only two pointers.

#include <iostream>
using namespace std;

// Definition for singly-linked list node.
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

//slow and fast pointer approach to find the middle node
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;   //it means " slow++ ""
            fast = fast->next->next;// it means " fast+2 "
        }

        return slow;
    }
};

// Print the linked list from a given node
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution s;
    ListNode* middle = s.middleNode(head);

    cout << "Middle Node: " << middle->val << endl;


    return 0;
}

// LeetCode Problem: 876 // https://leetcode.com/problems/middle-of-the-linked-list/