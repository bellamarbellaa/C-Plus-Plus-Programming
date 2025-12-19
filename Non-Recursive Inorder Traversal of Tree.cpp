#include <iostream>          // For input/output using cout, cin
#include <stack>             // For using stack (LIFO structure)
using namespace std;         // Avoid writing std:: repeatedly

// Definition of a tree node
struct Node {
    int data;                // Stores value of the node
    Node *left, *right;      // Pointers to left and right child

    // Constructor to create a new node
    Node(int value) {
        data = value;        // Set the node's data
        left = right = NULL;  // Initialize children to null
    }
};

// Inorder traversal WITHOUT recursion (uses stack)
void inorderWithoutRecursion(Node* root) {

    stack<Node*> s;          // Step 1: create an empty stack
    Node* current = root;    // Step 2: start from the root node

    // Run while stack is not empty OR current node is not null
    while (current != NULL|| !s.empty()) {

        // Step 3: Go to the leftmost node
        while (current != NULL) {
            s.push(current); // Push current node to stack
            current = current->left; // Move to left child
        }

        // Step 4: Current is NULL ? pop from stack
        current = s.top();   // Get the top node
        s.pop();             // Remove it from the stack

        // Step 5: Visit the node
        cout << current->data << " ";

        // Step 6: Go to the right subtree
        current = current->right;
    }
}

int main() {

    /* Tree used
              1
             / \
            2   3
           / \
          4   5
       Inorder output = 4 2 5 1 3
    */

    Node* root = new Node(1);        // Create root node
    root->left = new Node(2);        // Left child of root
    root->right = new Node(3);       // Right child of root
    root->left->left = new Node(4);  // Left child of node 2
    root->left->right = new Node(5); // Right child of node 2

    cout << "Inorder traversal (non-recursive): ";  // Print title
    inorderWithoutRecursion(root);                  // Perform traversal
    cout << endl;                                   // New line


    return 0;                                       // End program
}

