/*
    Problem: Boundary Traversal of a Binary Tree
    LeetCode: -
    Difficulty: Medium
    Topic: Binary Tree, Traversal, DFS

    Problem Statement:
    Given the root of a binary tree, perform its boundary traversal
    in an anti-clockwise direction.

    Boundary Traversal consists of:
    1. Root node
    2. Left boundary excluding leaf nodes
    3. All leaf nodes from left to right
    4. Right boundary excluding leaf nodes in reverse order

    Example:

                1
               / \
              2   7
             / \   \
            3   4   8
               / \   \
              5   6   9

    Output:
    1 -> 2 -> 3 -> 5 -> 6 -> 9 -> 8 -> 7
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool isLeaf(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            return true;
        }
        return false;
    }

    void addLeftBoundary(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->left;
        while(curr != NULL){
            if(!isLeaf(curr)) res.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaves(TreeNode* root, vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->val);
            return;
        }
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }

    void addRightBoundary(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->right;
        stack<int> st;
        while(curr){
            if(!isLeaf(curr)) st.push(curr->val);
            if(curr->right) curr = curr->right;
            else curr=curr->left;
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->val);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

int main() {

    /*
                1
               / \
              2   7
             / \   \
            3   4   8
               / \   \
              5   6   9
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    root->right->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    Solution solution;

    vector<int> ans = solution.boundary(root);

    cout << "Boundary Traversal: ";

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];

        if(i != ans.size() - 1){
            cout << " -> ";
        }
    }

    cout << endl;

    return 0;
}