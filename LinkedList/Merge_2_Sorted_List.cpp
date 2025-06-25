// DSA With Vishal - Merge Two Sorted Linked Lists

// Problem Statement:
// Merge two sorted linked lists and return it as a new sorted list.
// The new list should be made by splicing together the nodes of the first two lists.

// Approach:
// Use a dummy node and compare the heads of both lists, attaching the smaller node to the merged list.
// Continue until one list is exhausted, then attach the remaining part of the other list.

// Example:
// Input: 1->3->5->NULL , 2->3->6->NULL
// Output: 1->2->3->5->6->NULL

// Time Complexity: O(n + m), where n and m are the lengths of the two lists.
// Space Complexity: O(1), as we only use a few pointers.

#include <iostream>
using namespace std;

// Definition for singly-linked list node.
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Merge two sorted linked lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
      if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        if(head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else{
             head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
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
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Solution s;
    ListNode* merged = s.mergeTwoLists(head1, head2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

// LeetCode Problem: 21 // https://leetcode.com/problems/merge-two-sorted-lists/