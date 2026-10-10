/*
    Problem: Binary Tree Inorder Traversal
    LeetCode: 94
    Difficulty: Easy
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the root of a binary tree, return the inorder traversal
    of its nodes' values.

    Inorder Traversal:
        Left -> Root -> Right

    Approach:
    Use recursion to traverse the binary tree.

    1. If the root is nullptr, return an empty vector.
    2. Recursively find the inorder traversal of the left subtree.
    3. Add the root value to the answer.
    4. Recursively find the inorder traversal of the right subtree.
    5. Append the left subtree, root, and right subtree results.

    Time Complexity: O(n)
    Space Complexity: O(n)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root==nullptr){
            return ans;
        }
        vector<int>left = inorderTraversal(root->left);
        vector<int>right = inorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

int main() {
    Solution sol;

    /*
            1
             \
              2
             /
            3

        Inorder: 1 3 2
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = sol.inorderTraversal(root);

    cout << "[";

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];

        if(i != ans.size() - 1){
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}