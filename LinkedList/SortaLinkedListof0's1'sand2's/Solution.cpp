#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* zeroHead = new ListNode(-1);
        ListNode* oneHead = new ListNode(-1);
        ListNode* twoHead = new ListNode(-1);

        ListNode* zero = zeroHead;
        ListNode* one = oneHead;
        ListNode* two = twoHead;

        ListNode* temp = head;

        while (temp != nullptr) {
            // Save next node before changing temp->next
            ListNode* nextNode = temp->next;

            // Detach current node
            temp->next = nullptr;

            if (temp->data == 0) {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = temp;
            }
            else {
                two->next = temp;
                two = temp;
            }

            temp = nextNode;
        }

        // Connect 0 -> 1 -> 2
        if (oneHead->next != nullptr) {
            zero->next = oneHead->next;
            one->next = twoHead->next;
        }
        else {
            zero->next = twoHead->next;
        }

        ListNode* newHead = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data;

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
    // 1 -> 0 -> 2 -> 1 -> 2 -> 0 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next = new ListNode(1);

    cout << "Before sorting: ";
    printList(head);

    Solution solution;
    head = solution.sortList(head);

    cout << "After sorting:  ";
    printList(head);

    deleteList(head);

    return 0;
}