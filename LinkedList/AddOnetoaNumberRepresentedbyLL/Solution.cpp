/*
    Problem: Add One to a Number Represented by Linked List
    Difficulty: Medium
    Topic: Linked List, Recursion

    Problem Statement:
    Given a linked list where each node contains a single digit
    representing a non-negative integer, add 1 to the number and
    return the resulting linked list.

    The digits are stored in the same order as they appear in the
    number.

    Approach:
    Use recursion to reach the last node of the linked list first.

    1. Recursively move to the end of the list.
    2. Start adding 1 from the last digit.
    3. If the digit becomes less than 10, there is no carry.
    4. If the digit becomes 10, set it to 0 and return a carry of 1.
    5. Propagate the carry toward the beginning of the list.
    6. If a carry remains after processing the head, create a new
       node with value 1 and make it the new head.

    Time Complexity: O(n)
    Space Complexity: O(n)
    The O(n) space is due to the recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int data1) {
        val = data1;
        next = nullptr;
    }

    ListNode(int data1, ListNode* next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:

    int helperadd(ListNode* temp) {
        if (temp == nullptr) {
            return 1;
        }

        int carry = helperadd(temp->next);

        temp->val += carry;

        if (temp->val < 10) {
            return 0;
        }

        temp->val = 0;
        return 1;
    }

    ListNode* addOne(ListNode* head) {
        int carry = helperadd(head);

        if (carry == 1) {
            ListNode* newnode = new ListNode(1);
            newnode->next = head;
            return newnode;
        }

        return head;
    }
};

ListNode* createList(int n) {
    if (n == 0) {
        return nullptr;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the digits: ";

    ListNode* head = createList(n);

    cout << "Original number: ";
    printList(head);

    Solution solution;

    head = solution.addOne(head);

    cout << "After adding one: ";
    printList(head);

    return 0;
}