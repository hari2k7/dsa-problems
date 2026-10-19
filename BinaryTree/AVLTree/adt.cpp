#include <bits/stdc++.h>
using namespace std;

// -------------------- AVL Node --------------------
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// -------------------- AVL Tree ADT --------------------
class AVLTree {
private:
    TreeNode* root;

    // Get height
    int getHeight(TreeNode* node) {
        if (node == nullptr)
            return 0;

        return node->height;
    }

    // Get balance factor
    int getBalance(TreeNode* node) {
        if (node == nullptr)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    // Right Rotation
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        return x;
    }

    // Left Rotation
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        return y;
    }

    // Insert
    TreeNode* insert(TreeNode* node, int value) {

        // Normal BST insertion
        if (node == nullptr)
            return new TreeNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);

        else if (value > node->data)
            node->right = insert(node->right, value);

        else
            return node;   // Duplicate not allowed


        // Update height
        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));


        // Get balance factor
        int balance = getBalance(node);


        // ---------------- LL Case ----------------
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);


        // ---------------- RR Case ----------------
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);


        // ---------------- LR Case ----------------
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }


        // ---------------- RL Case ----------------
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
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

public:

    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Public insert
    void insert(int value) {
        root = insert(root, value);
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

    AVLTree tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(28);
    tree.insert(40);
    tree.insert(50);

    cout << "Inorder: ";
    tree.inorderTraversal();

    cout << "Preorder: ";
    tree.preorderTraversal();

    cout << "Postorder: ";
    tree.postorderTraversal();

    return 0;
}