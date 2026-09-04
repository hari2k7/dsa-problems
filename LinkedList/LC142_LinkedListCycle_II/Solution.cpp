/*
    Problem: Linked List Cycle II
    LeetCode: 142
    Difficulty: Medium
    Topic: Linked List, Two Pointers, Fast and Slow Pointers

    Problem Statement:
    Given the head of a linked list, return the node where the cycle
    begins. If there is no cycle, return nullptr.

    A cycle exists if there is some node in the list that can be
    reached again by continuously following the next pointer.

    Approach:
    Use Floyd's Cycle Detection Algorithm.

    1. Use slow and fast pointers to detect whether a cycle exists.
    2. If slow and fast meet, a cycle exists.
    3. Move slow back to the head.
    4. Move both slow and fast one step at a time.
    5. The node where they meet again is the starting node of the cycle.
    6. If no meeting occurs, return nullptr.

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
    ListNode *detectCycle(ListNode *head) {

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

int main() {
    // Create:
    // 1 -> 2 -> 3 -> 4
    //      ^         |
    //      |_________|

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

    ListNode* cycleStart = obj.detectCycle(head);

    if (cycleStart != nullptr) {
        cout << "Cycle starts at node: " << cycleStart->val << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}