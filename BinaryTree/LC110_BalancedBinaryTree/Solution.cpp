/*
    Problem: Balanced Binary Tree
    LeetCode: 110
    Difficulty: Easy
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the root of a binary tree, determine if it is height-balanced.

    A height-balanced binary tree is a binary tree in which the depth
    of the two subtrees of every node never differs by more than 1.

    Approach:
    Use a bottom-up recursive approach.

    The check() function returns:
    - The height of the subtree if it is balanced.
    - -1 if the subtree is unbalanced.

    For every node:
    1. Find the height of the left subtree.
    2. If the left subtree is unbalanced, return -1.
    3. Find the height of the right subtree.
    4. If the right subtree is unbalanced, return -1.
    5. If the height difference is greater than 1, return -1.
    6. Otherwise, return the height of the current subtree.

    Time Complexity: O(n)
    Space Complexity: O(h)
    where h is the height of the binary tree.
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
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    int check(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int lh = check(node->left);
        if(lh==-1) return -1;
        int rh = check(node->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;

        return 1+max(lh,rh);
    }
};

int main() {
    /*
            3
           / \
          9  20
             / \
            15  7

        Balanced: true
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    if(obj.isBalanced(root)){
        cout << "Balanced" << endl;
    }else{
        cout << "Not Balanced" << endl;
    }

    return 0;
}