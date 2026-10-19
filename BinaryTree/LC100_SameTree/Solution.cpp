/*
    Problem: Same Tree
    LeetCode: 100
    Difficulty: Easy
    Topic: Binary Tree, Recursion, Depth-First Search

    Problem Statement:
    Given the roots of two binary trees p and q, check whether they
    are the same tree.

    Two binary trees are considered the same if they are structurally
    identical and the nodes have the same values.

    Approach:
    Use recursion to compare both trees simultaneously.

    1. If either node is NULL, return whether both nodes are NULL.
    2. Compare the values of the current nodes.
    3. Recursively compare the left subtrees.
    4. Recursively compare the right subtrees.
    5. Return true only if all three conditions are satisfied.

    Time Complexity: O(n)
    Space Complexity: O(h)
    where h is the height of the tree.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p==q;
        }
        
        return (p->val == q->val)&& isSameTree(p->left, q->left)&& isSameTree(p->right, q->right);
    }
};

int main() {
    /*
        Tree 1:       1
                    /   \
                   2     3

        Tree 2:       1
                    /   \
                   2     3

        Result: true
    */

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if(obj.isSameTree(p, q)){
        cout << "Same Tree" << endl;
    }else{
        cout << "Different Trees" << endl;
    }

    return 0;
}