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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Remove head
        if (fast == nullptr) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        ListNode* slow = head;

        // Move slow and fast until fast reaches the last node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete slow->next
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};

ListNode* createList(vector<int>& arr) {
    if (arr.empty())
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << '\n';
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(arr);

    cout << "Original: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "Result:   ";
    printList(head);

    deleteList(head);

    return 0;
}