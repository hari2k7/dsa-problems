/*
    Problem: Reverse Nodes in k-Group
    LeetCode: 25
    Difficulty: Hard
    Topic: Linked List, Recursion, Iteration

    Problem Statement:
    Given the head of a linked list, reverse the nodes of the list
    k at a time and return the modified list.

    If the number of nodes is not a multiple of k, the remaining
    nodes at the end should remain in their original order.

    The nodes themselves must be rearranged, not just their values.

    Approach:
    Traverse the linked list and process exactly k nodes at a time.

    1. Find the kth node from the current position.
    2. If fewer than k nodes remain, leave them unchanged.
    3. Disconnect the current group from the rest of the list.
    4. Reverse the current group.
    5. Connect the reversed group to the previous group.
    6. Continue with the next group.

    Time Complexity: O(n)
    Space Complexity: O(1)
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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }

        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp != nullptr) {

            ListNode* kNode = temp;

            for (int i = 0; i < k - 1; i++) {
                kNode = kNode->next;


                if (kNode == nullptr) {
                    if (prevNode != nullptr) {
                        prevNode->next = temp;
                    }

                    return head;
                }
            }

            ListNode* nextNode = kNode->next;

            kNode->next = nullptr;

            reverse(temp);

            if (temp == head) {

                head = kNode;
            } else {

                prevNode->next = kNode;
            }

            prevNode = temp;

            temp = nextNode;
        }

        return head;
    }
};

ListNode* createList(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;

    for (int i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
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

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.reverseKGroup(head, k);

    cout << "After reversing in groups of " << k << ": ";
    printList(head);

    deleteList(head);

    return 0;
}