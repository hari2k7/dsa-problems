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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            even->next = odd->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

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
    while (head) {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << '\n';
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = createList(arr);

    cout << "Original: ";
    printList(head);

    Solution sol;
    head = sol.oddEvenList(head);

    cout << "Result:   ";
    printList(head);

    deleteList(head);

    return 0;
}