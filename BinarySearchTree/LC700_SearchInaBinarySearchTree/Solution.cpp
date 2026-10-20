/*
    Problem: Search in a Binary Search Tree
    LeetCode: 700
    Difficulty: Easy
    Topic: Binary Search Tree, Iteration

    Problem Statement:
    Given the root of a Binary Search Tree and an integer value,
    find the node whose value is equal to the given value and
    return the subtree rooted at that node. If the node does not
    exist, return nullptr.

    Approach:
    Start from the root and use the BST property.
    If the current node value is smaller than the target, move
    to the right subtree. If it is greater, move to the left
    subtree. Return the node when the value is found.

    Time Complexity: O(h)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val==val){
                return temp;
            }else if(temp->val<val){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        return NULL;
    }
};

void inorder(TreeNode* root) {
    if(root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    /*
            4
           / \
          2   7
         / \
        1   3

        Search: 2

        Result subtree:
            2
           / \
          1   3
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;

    Solution solution;

    TreeNode* result = solution.searchBST(root, val);

    if(result != nullptr) {
        cout << "Subtree rooted at " << val << ": ";
        inorder(result);
        cout << endl;
    } else {
        cout << "Value not found" << endl;
    }

    return 0;
}