/*
    Problem: Binary Tree Zigzag Level Order Traversal
    LeetCode: 103
    Difficulty: Medium
    Topic: Binary Tree, BFS, Queue, Level Order Traversal

    Problem Statement:
    Given the root of a binary tree, return the zigzag level order
    traversal of its nodes' values.

    The first level is traversed from left to right, the next level
    from right to left, and so on, alternating between the two
    directions.

    Approach:
    Use Breadth-First Search (BFS) with a queue.

    1. Push the root into the queue.
    2. Process one level at a time.
    3. Create a vector of the current level's size.
    4. If traversing left to right, place values normally.
    5. If traversing right to left, place values in reverse positions.
    6. Add the current level to the answer.
    7. Toggle the traversal direction after every level.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       if(root==nullptr) return ans;
       
       queue<TreeNode*>q;
       q.push(root);

       bool leftToRight = true;

       while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : size-1-i;

            row[index] = node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(row);
        leftToRight = !leftToRight;
       }

       return ans;
    }
};

int main() {
    /*
            3
           / \
          9  20
             / \
            15  7

        Zigzag Traversal:
        [
            [3],
            [20, 9],
            [15, 7]
        ]
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.zigzagLevelOrder(root);

    cout << "[" << endl;

    for(int i = 0; i < ans.size(); i++){
        cout << "  [";

        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j];

            if(j != ans[i].size() - 1){
                cout << ", ";
            }
        }

        cout << "]";

        if(i != ans.size() - 1){
            cout << ",";
        }

        cout << endl;
    }

    cout << "]" << endl;

    return 0;
}