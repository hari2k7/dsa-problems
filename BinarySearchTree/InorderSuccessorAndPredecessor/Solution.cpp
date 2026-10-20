/*
    Problem: Inorder Successor and Predecessor in BST
    LeetCode: -
    Difficulty: Medium
    Topic: Binary Search Tree

    Problem Statement:
    Given a Binary Search Tree and a key, find the inorder
    predecessor and inorder successor of the given key.

    Return:
    [predecessor, successor]

    Example:
    BST:

            8
           / \
          3   10
         / \    \
        1   6    14
           / \   /
          4   7 13

    Key = 6

    Inorder:
    1 3 4 6 7 8 10 13 14

    Predecessor = 4
    Successor = 7

    Approach:
    Use the BST property to find the predecessor and successor
    without performing a complete inorder traversal.

    Time Complexity: O(h)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    vector<int> succPredBST(TreeNode* root, int key) {
        vector<int> ans = {-1,-1};

        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->data > key){
                ans[1] = cur->data;
                cur = cur->left;
            }else{
                cur = cur->right;
            }
        }

        cur = root;
        while(cur != NULL){
            if(cur->data < key){
                ans[0] = cur->data;
                cur = cur->right;
            }else{
                cur = cur->left;
            }
        }

        return ans;
    }
};

int main() {

    /*
                8
               / \
              3   10
             / \    \
            1   6    14
               / \   /
              4   7 13

        Key = 6

        Predecessor = 4
        Successor = 7
    */

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    int key = 6;

    Solution solution;

    vector<int> ans = solution.succPredBST(root, key);

    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;
}
