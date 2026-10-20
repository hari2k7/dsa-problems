/*
    Problem: Delete Node in a BST
    LeetCode: 450
    Difficulty: Medium
    Topic: Binary Search Tree, Recursion

    Problem Statement:
    Given the root of a Binary Search Tree and a key, delete the node
    with the given key and return the root of the BST.

    Approach:
    Search for the node using the BST property.

    There are three cases:
    1. Node has no left child -> replace it with the right subtree.
    2. Node has no right child -> replace it with the left subtree.
    3. Node has two children -> find the inorder successor
       (smallest node in the right subtree), replace the node's value
       with the successor's value, and delete the successor.

    Time Complexity: O(h)
    Space Complexity: O(h)
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }

        if(key<root->val){
            root->left = deleteNode(root->left, key);
        }else if(key>root->val){
            root->right = deleteNode(root->right, key);
        }else{
            
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = root->right;

            while(temp->left != nullptr){
                temp = temp->left;
            }

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

void inorder(TreeNode* root) {
    if(root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    /*
                5
               / \
              3   6
             / \   \
            2   4   7
           
        Delete: 3

        Result:
                5
               / \
              4   6
             /     \
            2       7

        Inorder: 2 4 5 6 7
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    int key = 3;

    Solution solution;

    root = solution.deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}