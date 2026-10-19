/*
    Problem: Maximum Depth of Binary Tree
    LeetCode: 104
    Difficulty: Easy
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the root of a binary tree, return its maximum depth.

    The maximum depth is the number of nodes along the longest path
    from the root node down to the farthest leaf node.

    Approach:
    Use recursion.

    - If the root is nullptr, the depth is 0.
    - Recursively find the maximum depth of the left subtree.
    - Recursively find the maximum depth of the right subtree.
    - Take the maximum of both depths and add 1 for the current node.

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
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

int main() {
    /*
            3
           / \
          9  20
             / \
            15  7

        Maximum Depth = 3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Depth: " << obj.maxDepth(root) << endl;

    return 0;
}