/*
    Problem: Sort List
    LeetCode: 148
    Difficulty: Medium
    Topic: Linked List, Sorting, Merge Sort, Recursion

    Problem Statement:
    Given the head of a linked list, return the list after sorting
    it in ascending order.

    Approach:
    Use Merge Sort on the linked list.

    1. Find the middle of the linked list using slow and fast pointers.
    2. Split the list into two halves.
    3. Recursively sort both halves.
    4. Merge the two sorted halves using the merge function.
    5. Return the merged sorted list.

    Time Complexity: O(n log n)
    Space Complexity: O(log n)
    The O(log n) space is due to the recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* tempNode = new ListNode(-1);
        ListNode* temp = tempNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        ListNode* result = tempNode->next;
        delete tempNode;
        return result;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge(leftHead, rightHead);
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    // Input: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Before sorting: ";
    printList(head);

    Solution solution;
    head = solution.sortList(head);

    cout << "After sorting:  ";
    printList(head);

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}