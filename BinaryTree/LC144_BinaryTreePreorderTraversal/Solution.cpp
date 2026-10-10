 /*
    Problem: Binary Tree Preorder Traversal
    LeetCode: 144
    Difficulty: Easy
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the root of a binary tree, return the preorder traversal
    of its nodes' values.

    Preorder Traversal:
        Root -> Left -> Right

    Approach:
    Use recursion to traverse the binary tree.

    1. If the root is nullptr, return an empty vector.
    2. Add the root value to the answer.
    3. Recursively find the preorder traversal of the left subtree.
    4. Recursively find the preorder traversal of the right subtree.
    5. Append the left and right subtree results to the answer.

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        ans.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
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

        Preorder: 1 2 3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = sol.preorderTraversal(root);

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