/*
    Problem: Linked List Cycle
    LeetCode: 141
    Difficulty: Easy
    Topic: Linked List, Two Pointers, Fast and Slow Pointers

    Problem Statement:
    Given the head of a linked list, determine if the linked list
    has a cycle in it.

    A cycle exists if there is some node in the list that can be
    reached again by continuously following the next pointer.

    Approach:
    Use Floyd's Cycle Detection Algorithm with two pointers:

    - slow moves one step at a time.
    - fast moves two steps at a time.
    - If there is a cycle, slow and fast will eventually meet.
    - If fast reaches nullptr, there is no cycle.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    // Create: 1 -> 2 -> 3 -> 4
    //              ^         |
    //              |_________|
    
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create cycle: 4 -> 2
    node4->next = node2;

    Solution obj;

    if (obj.hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}