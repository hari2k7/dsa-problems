/*
    Problem: Binary Tree Maximum Path Sum
    LeetCode: 124
    Difficulty: Hard
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the root of a binary tree, return the maximum path sum
    of any non-empty path.

    A path is a sequence of nodes where each pair of adjacent nodes
    in the sequence has an edge connecting them. A node cannot appear
    more than once in the sequence.

    Approach:
    Use recursion to calculate the maximum path sum that can be
    extended upward from each node.

    For every node:
    1. Calculate the maximum contribution from the left subtree.
    2. Calculate the maximum contribution from the right subtree.
    3. Ignore negative contributions using max(0, ...).
    4. The path passing through the current node is:
           node->val + left + right
    5. Update the global maximum.
    6. Return the maximum single-side path that can be extended
       to the parent:
           node->val + max(left, right)

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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathdown(root, maxi);
        return maxi;
    }

    int maxPathdown(TreeNode* node, int &maxi){
        if(node == NULL) return 0;
        int left = max(0,maxPathdown(node->left, maxi));
        int right = max(0,maxPathdown(node->right, maxi));
        maxi = max(maxi, node->val + left + right);
        return max(left, right)+node->val;
    }
};

int main() {
    /*
            -10
            / \
           9  20
              / \
             15  7

        Maximum Path Sum = 42
        Path: 15 -> 20 -> 7
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum: " << obj.maxPathSum(root) << endl;

    return 0;
}