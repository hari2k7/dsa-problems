/*
    Problem: Find Floor and Ceil in a Binary Search Tree
    LeetCode: -
    Difficulty: Easy
    Topic: Binary Search Tree

    Problem Statement:
    Given the root of a Binary Search Tree and a target value x:

    - Floor: The largest value in the BST that is less than or equal to x.
    - Ceil: The smallest value in the BST that is greater than or equal to x.

    Example:
    BST: [8, 3, 10, 1, 6, 14, 4, 7, 13]
    x = 5

    Floor = 4
    Ceil = 6

    Approach:
    Use the BST property to search for the floor and ceil efficiently.

    Floor:
    - If current value == x, you found the floor.
    - If current value < x, it can be a possible floor.
    - Otherwise, move to the left subtree.

    Ceil:
    - If current value == x, you found the ceil.
    - If current value > x, it can be a possible ceil.
    - Otherwise, move to the right subtree.

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

    int findFloor(TreeNode* root, int x) {
        TreeNode* temp = root;
        int r = -1;

        while(temp!=NULL){
            if(temp->val==x){
                return temp->val;
            }
            else if(temp->val<x){
                r = temp->val;
                temp = temp->right;
            }else{
                temp = temp->left;
            }
            
        }

        return r;
    }

    int findCeil(TreeNode* root, int x) {
        TreeNode* temp = root;
        int r = -1;

        while(temp!=NULL){
            if(temp->val==x){
                return temp->val;
            }
            else if(temp->val>x){
                r = temp->val;
                temp = temp->left;
            }else{
                temp = temp->right;
            }
            
        }

        return r;
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

        Target = 5

        Floor = 4
        Ceil = 6
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

    int x = 5;

    Solution solution;

    int floorValue = solution.findFloor(root, x);
    int ceilValue = solution.findCeil(root, x);

    cout << "Target: " << x << endl;
    cout << "Floor: " << floorValue << endl;
    cout << "Ceil: " << ceilValue << endl;

    return 0;
}