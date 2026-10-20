#include <bits/stdc++.h>
using namespace std;

// -------------------- Tree Node --------------------
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// -------------------- BST ADT --------------------
class BST {
private:
    TreeNode* root;

    // Recursive insertion
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Inorder
    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder
    void preorder(TreeNode* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder
    void postorder(TreeNode* node) {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Search
    bool search(TreeNode* node, int value) {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

public:

    // Constructor
    BST() {
        root = nullptr;
    }

    // Insert
    void insert(int value) {
        root = insert(root, value);
    }

    // Search
    bool search(int value) {
        return search(root, value);
    }

    // Traversals
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorder(root);
        cout << endl;
    }
};


// -------------------- Main --------------------
int main() {

    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.inorderTraversal();

    cout << "Preorder: ";
    tree.preorderTraversal();

    cout << "Postorder: ";
    tree.postorderTraversal();

    int key = 40;

    if (tree.search(key))
        cout << key << " found" << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}