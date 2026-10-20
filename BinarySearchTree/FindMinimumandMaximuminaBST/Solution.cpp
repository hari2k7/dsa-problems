/*
    Problem: Find Minimum and Maximum in a Binary Search Tree
    LeetCode: -
    Difficulty: Easy
    Topic: Binary Search Tree

    Problem Statement:
    Given the root of a Binary Search Tree, find the minimum and
    maximum values present in the tree.

    Approach:
    Remember the property of a BST:
    - The minimum value is found by following the ______ pointers.
    - The maximum value is found by following the ______ pointers.

    Time Complexity: O(h)
    Space Complexity: O(1)
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

    int findMin(TreeNode* root) {
        int min = root->val;
        TreeNode* temp = root;

        while(temp!=NULL){
            if(temp->val < min){
                min = temp->val;
            }
            temp = temp->left;
        }
        return min;
    }

    int findMax(TreeNode* root) {
        int max = root->val;
        TreeNode* temp = root;

        while(temp!=NULL){
            if(temp->val > max){
                max = temp->val;
            }
            temp = temp->right;
        }
        return max;
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

        Minimum = ?
        Maximum = ?
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

    Solution solution;

    int minimum = solution.findMin(root);
    int maximum = solution.findMax(root);

    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    return 0;
}