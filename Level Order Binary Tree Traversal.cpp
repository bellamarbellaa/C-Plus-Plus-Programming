#include <iostream>          // Include input/output library
#include <queue>             // Include queue library for BFS
using namespace std;         // Use standard namespace

// Define a Node structure for the binary tree
struct Node {
    int data;                // Store integer value of the node
    Node *left;              // Pointer to left child
    Node *right;             // Pointer to right child

    // Constructor to create a new node with a given value
    Node(int value) {
        data = value;        // Initialize node value
        left = right = NULL;  // Initialize both children as null
    }
};

// Level-order traversal using queue (BFS)
void printLevelOrder(Node *root) {
    if (root == NULL) return;  // If tree is empty, stop

    queue<Node*> q;          // Create an empty queue
    q.push(root);            // Push the root into the queue

    while (!q.empty()) {     // Loop while queue is not empty
        Node *temp_node = q.front(); // Get the front node
        q.pop();             // Remove it from the queue

        cout << temp_node->data << " ";  // Print the node's value

        if (temp_node->left != NULL)   // If left child exists
            q.push(temp_node->left);      // Push left child into queue

        if (temp_node->right != NULL)  // If right child exists
            q.push(temp_node->right);     // Push right child into queue
    }
}

int main() {

    /* Example tree:
             1
            / \
           2   3
          / \
         4   5
    */

    Node *root = new Node(1);        // Create root node
    root->left = new Node(2);        // Left child of root
    root->right = new Node(3);       // Right child of root
    root->left->left = new Node(4);  // Left child of node 2
    root->left->right = new Node(5); // Right child of node 2

    cout << "Level order traversal (using queue): ";  // Print header
    printLevelOrder(root);                            // Perform BFS traversal
    cout << endl;                                      // New line

    return 0;                                          // End program
}

