#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inOrderTraversal(Node* node) {
    if (node == NULL) return;
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

void preOrderTraversal(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void postOrderTraversal(Node* node) {
    if (node == NULL) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}

int main() {

    // ------------------------------------------------------
    // Balanced Binary Tree Structure
    //
    //            1
    //          /   \
    //         2     3
    //        / \     \
    //       4   5     6
    //
    // Height(Left Subtree)  = 2
    // Height(Right Subtree) = 2
    // ? Balanced (difference <= 1)
    // ------------------------------------------------------

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);


    // ------------------------------------------------------
    // Traversals
    // ------------------------------------------------------
    cout << "Inorder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}

