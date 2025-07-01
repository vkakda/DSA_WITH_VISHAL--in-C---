// DSA With Vishal - Swap Nodes in Pairs

// Problem Statement:
// Given a linked list, swap every two adjacent nodes and return its head.
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed).

// Approach:
// We swap every two adjacent nodes by changing their next pointers. 
// We use an iterative approach with a dummy node to simplify edge cases.

// Example:
// Input: 1->2->3->4
// Output: 2->1->4->3

// Time Complexity: O(n), where n is the number of nodes in the list.
// Space Complexity: O(1)

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //base case
        if( head ==NULL || head->next == NULL) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = NULL;

        while (first != NULL && second != NULL) {
            ListNode* third = second->next;

            // Swapping
            second->next = first; // second points to first
            first->next = third; // first points to the node after second

            // If prev is not NULL, link it to the new first
            if (prev != NULL) {
                prev->next = second; // prev points to second
            } else {
                head = second; // Update head if this is the first pair
            }

            // Move prev to first, and update first and second for the next pair
            prev = first;
            first = third; // Move first to the next pair
            if (third != NULL) {
                second = third->next; // Move second to the next pair
            } else {
                second = NULL; // No more pairs to swap
            }
        }
        return  head; // Return the new head of the list
    }
};

// Print the linked list from a given node
void printList(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage
    // Creating the linked list: 1->2->3->4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List: ";
    printList(head);

    Solution s;
    ListNode* result = s.swapPairs(head);

    cout << "After Swapping Pairs: ";
    printList(result);

    // Free memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}

// LeetCode Problem: 24 // https://leetcode.com/problems/swap-nodes-in-pairs/
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
          //base case
        if( head ==NULL || head->next == NULL) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = NULL;

        while (first != NULL && second != NULL) {
            ListNode* third = second->next;

            // Swapping
            second->next = first; // second points to first
            first->next = third; // first points to the node after second

            // If prev is not NULL, link it to the new first
            if (prev != NULL) {
                prev->next = second; // prev points to second
            } else {
                head = second; // Update head if this is the first pair
            }

            // Move prev to first, and update first and second for the next pair
            prev = first;
            first = third; // Move first to the next pair
            if (third != NULL) {
                second = third->next; // Move second to the next pair
            } else {
                second = NULL; // No more pairs to swap
            }
        }
        return  head; // Return the new head of the list
    }
};
*/