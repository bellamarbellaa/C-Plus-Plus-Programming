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

void preOrderTraversal(Node* node) {
    if(node == NULL) return;
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

int main() {
    cout << "First tree preorder traversal: ";
    Node* rootOne = new Node(1);
    rootOne->left = new Node(2);
    rootOne->right = new Node(3);
    rootOne->left->left = new Node(4);
    rootOne->left->right = new Node(5);
    rootOne->right->left = new Node(6);

    preOrderTraversal(rootOne);
    cout << endl;

    cout << "Second tree preorder traversal: ";
    Node* rootTwo = new Node(1);
    rootTwo->left = new Node(2);
    rootTwo->right = new Node(3);
    rootTwo->left->left = new Node(4);
    rootTwo->left->right = new Node(5);
    rootTwo->left->right->left = new Node(6);
    rootTwo->left->right->right = new Node(7);

    preOrderTraversal(rootTwo);
    cout << endl;

    return 0;
}

