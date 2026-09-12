/*
    Problem: Add Two Numbers
    LeetCode: 2
    Difficulty: Medium
    Topic: Linked List, Math

    Problem Statement:
    You are given two non-empty linked lists representing two
    non-negative integers.

    The digits are stored in reverse order, and each node contains
    a single digit. Add the two numbers and return the sum as a
    linked list.

    The two numbers do not contain any leading zeros, except for
    the number 0 itself.

    Approach:
    Traverse both linked lists simultaneously while maintaining
    a carry.

    1. Add the current digits from both lists along with the carry.
    2. Create a new node with sum % 10.
    3. Update carry as sum / 10.
    4. Continue until both lists are exhausted and there is no carry.
    5. Return the resulting linked list.

    Time Complexity: O(max(n, m))
    Space Complexity: O(max(n, m))
    where n and m are the lengths of the two linked lists.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* ptr = &dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;

            carry = sum / 10;
        }

        return dummy.next;
    }
};

ListNode* createList(initializer_list<int> values) {
    ListNode dummy(0);
    ListNode* ptr = &dummy;

    for (int value : values) {
        ptr->next = new ListNode(value);
        ptr = ptr->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case:
    // l1 = [2,4,9]
    // l2 = [5,6,4,9]
    //
    // Represents:
    // 942 + 9465 = 10407
    //
    // Result:
    // [7,0,4,0,1]

    ListNode* l1 = createList({2, 4, 9});
    ListNode* l2 = createList({5, 6, 4, 9});

    Solution solution;

    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "l1     : ";
    printList(l1);

    cout << "l2     : ";
    printList(l2);

    cout << "Result : ";
    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return 0;
}