// DSA With Vishal - Reverse Nodes in k-Group

// Problem Statement:
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// Approach:
// We reverse every k nodes in the list. If the number of nodes left is less than k, we leave them as is.
// We use an iterative approach to reverse k nodes at a time and connect the reversed parts properly.

// Example:
// Input: 1->2->3->4->5, k = 3
// Output: 3->2->1->4->5

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        //check if K node exist
        int count = 0;
        while(count<k) {
            if(temp == NULL) return head;
            temp = temp->next;
            count++;
        }

        //recursive call for rest of the LL
        ListNode* prevNode= reverseKGroup(temp, k);

        //Reverse the current group
        temp= head; count = 0;
        while(count<k){
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;

            count++;
        }

        return prevNode;
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
    // Creating the linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    int k = 3;
    Solution s;
    ListNode* result = s.reverseKGroup(head, k);

    cout << "Reversed in " << k << "-Group: ";
    printList(result);

    // Free memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}

// LeetCode Problem: 25 // https://leetcode.com/problems/reverse-nodes-in-k-group/
/*
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        //check if K node exist
        int count = 0;
        while(count<k) {
            if(temp == NULL) return head;
            temp = temp->next;
            count++;
        }

        //recursive call for rest of the LL
        ListNode* prevNode= reverseKGroup(temp, k);

        //Reverse the current group
        temp= head; count = 0;
        while(count<k){
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;

            count++;
        }

        return prevNode;
    }
};
*/