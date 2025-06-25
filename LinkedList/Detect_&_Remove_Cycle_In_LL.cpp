// DSA With Vishal - Detect & Remove Cycle In Linked List

// Problem Statement:
// Given the head of a singly linked list, detect if there is a cycle in the linked list.
// If a cycle is found, remove the cycle and restore the linked list to a linear structure.

// Approach:
// 1. Use Floyd's Cycle Detection Algorithm (slow and fast pointers) to detect a cycle.
// 2. If a cycle is detected, find the starting node of the cycle.
// 3. Remove the cycle by setting the last node's next pointer to NULL.

// Example:
// Input: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle back to node 3)
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), as we use only a constant number of pointers.

#include <iostream>
using namespace std;

// Definition for singly-linked list node.
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Detects and removes cycle if present
    void detectAndRemoveCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }    
        }

        return false;
    }

public:
    // Helper to remove the cycle
    void removeCycle(ListNode* head, ListNode* meetingPoint) {
         ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            } 
        }

        if (!isCycle) {
            return NULL;
        }


        slow = head;
        ListNode* prev = NULL;
        while(slow != fast ){
            slow = slow->next;
            prev = fast;
            fast = fast->next;

        }

        prev->next = NULL; // Remove the cycle

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
    

    return 0;
}

// LeetCode Problem: 141 // https://leetcode.com/problems/linked-list-cycle/
// LeetCode Problem: 142 // https://leetcode.com/problems/linked-list-cycle-ii/