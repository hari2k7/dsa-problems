/*
    Problem: Insert into a Binary Search Tree
    LeetCode: 701
    Difficulty: Medium
    Topic: Binary Search Tree, Iteration

    Problem Statement:
    Given the root of a Binary Search Tree and a value, insert the
    value into the BST and return the root of the resulting tree.

    Approach:
    Start from the root and use the BST property.
    If the current node value is smaller than the value to insert,
    move to the right subtree. Otherwise, move to the left subtree.
    When the required child is NULL, insert the new node there.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->val < val){
                if(curr->right == NULL){
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }else{
                if(curr->left == NULL){
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            }
        }
        return root;
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

        Insert: 5

        Result:
                4
               / \
              2   7
             / \ /
            1  3 5

        Inorder: 1 2 3 4 5 7
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;

    Solution solution;

    root = solution.insertIntoBST(root, val);

    cout << "Inorder after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}
