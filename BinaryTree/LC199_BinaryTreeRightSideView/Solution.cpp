/*
    Problem: Binary Tree Right Side View
    LeetCode: 199
    Difficulty: Medium
    Topic: Binary Tree, BFS, Queue

    Problem Statement:
    Given the root of a binary tree, imagine yourself standing on the
    right side of it. Return the values of the nodes you can see ordered
    from top to bottom.

    Approach:
    Use BFS (level-order traversal).
    For each level, add the value of the last node in that level
    because it is the rightmost node visible from the right side.

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(i==size-1) ans.push_back(node->val);
                if(node->left !=nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
        }
        
        return ans;
    }
};

int main() {

    /*
            1
           / \
          2   3
           \   \
            5   4

        Right Side View:
        1 -> 3 -> 4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;

    vector<int> ans = solution.rightSideView(root);

    cout << "Right Side View: ";

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];

        if(i != ans.size() - 1)
            cout << " -> ";
    }

    cout << endl;

    return 0;
}
