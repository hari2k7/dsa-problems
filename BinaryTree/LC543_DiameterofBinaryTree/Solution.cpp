/*
    Problem: Diameter of Binary Tree
    LeetCode: 543
    Difficulty: Easy
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the root of a binary tree, return the length of the
    diameter of the tree.

    The diameter of a binary tree is the length of the longest path
    between any two nodes in the tree. This path may or may not
    pass through the root.

    Approach:
    For every node, calculate the height of its left and right
    subtrees.

    The diameter passing through the current node is:
        left height + right height

    Keep updating the maximum diameter while calculating heights.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode* node,int &diameter){
        if(node==nullptr) return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh+rh);

        return 1+max(lh, rh);
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5

        Diameter = 3
        Path: 4 -> 2 -> 1 -> 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Diameter: " << obj.diameterOfBinaryTree(root) << endl;

    return 0;
}