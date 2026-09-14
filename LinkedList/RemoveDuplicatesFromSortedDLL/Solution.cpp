/*
    Problem: Remove Duplicates from Sorted Doubly Linked List
    Difficulty: Easy
    Topic: Doubly Linked List

    Problem Statement:
    Given a sorted doubly linked list, remove all duplicate nodes
    so that each value appears only once.

    The relative order of the remaining nodes should be preserved.

    Approach:
    Traverse the doubly linked list using a pointer.

    1. Compare the current node with its next node.
    2. If both values are equal, remove the duplicate node.
    3. Update the next pointer of the current node.
    4. Update the prev pointer of the node after the duplicate.
    5. If the values are different, move to the next node.
    6. Continue until the end of the list.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Definition of doubly linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode() {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }

    ListNode(int data1) {
        val = data1;
        next = nullptr;
        prev = nullptr;
    }

    ListNode(int data1, ListNode* next1, ListNode* prev1) {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:

    ListNode* removeDuplicates(ListNode* head) {

        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if(temp->val == temp->next->val){
                ListNode* duplicate = temp->next;
                temp->next = duplicate->next;
                if(duplicate->next != nullptr){
                    duplicate->next->prev = temp;
                }
                delete duplicate;
            }else{
                temp = temp->next;
            }
        }
        
        
        return head;
    }
};


// Create doubly linked list
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
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}


// Print list forward
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " <-> ";
        }

        head = head->next;
    }

    cout << endl;
}


// Free memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}


int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the elements: ";
    ListNode* head = createList(n);

    cout << "Original list: ";
    printList(head);


    Solution solution;

    head = solution.removeDuplicates(head);


    cout << "After removing duplicates: ";
    printList(head);


    deleteList(head);

    return 0;
}