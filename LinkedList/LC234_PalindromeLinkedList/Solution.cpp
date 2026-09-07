#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = head;
        ListNode* temp = head->next;

        prev->next = nullptr;

        while (temp != nullptr) {
            ListNode* nxt = temp->next;
            temp->next = prev;

            prev = temp;
            temp = nxt;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* middle = slow->next;
        ListNode* newHead = reverseList(middle);

        // Compare both halves
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;

        bool isp = true;

        while (temp2 != nullptr) {
            if (temp1->val != temp2->val) {
                isp = false;
                break;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Restore original list
        slow->next = reverseList(newHead);

        return isp;
    }
};

int main() {

    // Create palindrome:
    // 1 -> 2 -> 3 -> 2 -> 1

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution obj;

    if (obj.isPalindrome(head)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}