/*
    Problem: Binary Tree Postorder Traversal
    LeetCode: 145
    Difficulty: Easy
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the root of a binary tree, return the postorder traversal
    of its nodes' values.

    Postorder Traversal:
        Left -> Right -> Root

    Approach:
    Use recursion to traverse the binary tree.

    1. If the root is nullptr, return an empty vector.
    2. Recursively find the postorder traversal of the left subtree.
    3. Recursively find the postorder traversal of the right subtree.
    4. Append the left subtree results.
    5. Append the right subtree results.
    6. Add the root value at the end.

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root==nullptr){
            return ans;
        }

        vector<int>left=postorderTraversal(root->left);
        vector<int>right=postorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());
        ans.push_back(root->val);

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

        Postorder: 3 2 1
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = sol.postorderTraversal(root);

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