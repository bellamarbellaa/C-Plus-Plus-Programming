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

int main() {

    // ---------------------------------------
    // Degenerate Left-Skewed Tree Structure
    //
    //      1
    //     /
    //    2
    //   /
    //  3
    // /
    //4
    //
    // ---------------------------------------
    cout << "Degenerate Left-Skewed inorder: ";
    Node* leftDeg = new Node(1);
    leftDeg->left = new Node(2);
    leftDeg->left->left = new Node(3);
    leftDeg->left->left->left = new Node(4);

    inOrderTraversal(leftDeg);
    cout << endl;


    // ---------------------------------------
    // Degenerate Right-Skewed Tree Structure
    //
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    //
    // ---------------------------------------
    cout << "Degenerate Right-Skewed inorder: ";
    Node* rightDeg = new Node(1);
    rightDeg->right = new Node(2);
    rightDeg->right->right = new Node(3);
    rightDeg->right->right->right = new Node(4);

    inOrderTraversal(rightDeg);
    cout << endl;

    return 0;
}



