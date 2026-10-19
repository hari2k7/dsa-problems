/*
    Problem: Symmetric Tree
    LeetCode: 101
    Difficulty: Easy
    Topic: Binary Tree, Recursion

    Problem Statement:
    Given the root of a binary tree, check whether the tree is a
    mirror of itself, i.e., symmetric around its center.

    Approach:
    Recursively compare the left and right subtrees as mirror images.
    The values must be equal, and the left child of one subtree must
    match the right child of the other subtree.

    Time Complexity: O(n)
    Space Complexity: O(h)
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
    bool ismirror(TreeNode* left, TreeNode* right){
        if(left==nullptr && right==nullptr) return true;
        if(left==nullptr || right==nullptr) return false;
        if(left->val != right->val) return false;

        return ismirror(left->left, right->right) && ismirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return ismirror(root->left, root->right);
    }
};

int main() {

    /*
                1
               / \
              2   2
             / \ / \
            3  4 4  3

        Symmetric: true
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;

    if(solution.isSymmetric(root)){
        cout << "Tree is symmetric" << endl;
    }else{
        cout << "Tree is not symmetric" << endl;
    }

    return 0;
}