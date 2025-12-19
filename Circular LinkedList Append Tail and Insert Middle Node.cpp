#include <iostream>
using namespace std;

// Node class for circular singly linked list
class Node {
public:
    int value;       // store node data
    Node* next;      // pointer to next node

    // Constructor: initialize value and next pointer
    Node(int data = 0, Node* nextLoc = NULL) {
        value = data;
        next = nextLoc;
    }
};

/*--------------------------------------------
 Function: InsertAfter
 Purpose: Inserts nodeLoc right after current node
---------------------------------------------*/
void InsertAfter(Node* current, Node* nodeLoc) {
    nodeLoc->next = current->next;  // new node points to next node of current
    current->next = nodeLoc;        // current node now points to new node
}

/*--------------------------------------------
 Function: PrintCircular
 Purpose: Prints all nodes in a circular list
---------------------------------------------*/
void PrintCircular(Node* head) {
    if (head == NULL) {             // if list is empty
        cout << "Empty list\n";
        return;
    }

    Node* temp = head;              // start from head node

    // do-while ensures we print head once and stop when we loop back
    do {
        cout << temp->value << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

/*--------------------------------------------
 Function: Append
 Purpose: Add a new node at the end of the circular list
---------------------------------------------*/
void Append(Node** head_ref, int val) {
    Node* newNode = new Node(val);  // create a new node

    // Case 1: empty list — point new node to itself
    if (*head_ref == NULL) {
        newNode->next = newNode;    // circular link to itself
        *head_ref = newNode;        // new node becomes head
        return;
    }

    // Case 2: find the last node (points back to head)
    Node* last = *head_ref;
    while (last->next != *head_ref)
        last = last->next;

    last->next = newNode;           // last node points to new node
    newNode->next = *head_ref;      // new node points to head (circular)
}

/*--------------------------------------------
 Function: InsertAfterValue
 Purpose: Insert a new node after a specific value
---------------------------------------------*/
void InsertAfterValue(Node* head, int key, int val) {
    if (head == NULL) return;       // if list is empty, do nothing

    Node* temp = head;

    // traverse the circular list until we find the key or come back to head
    do {
        if (temp->value == key) {   // if we find the key
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return;                 // stop after inserting once
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << key << " not found.\n";
}

/*--------------------------------------------
 MAIN FUNCTION
---------------------------------------------*/
int main() {
    Node* head = NULL;              // start with an empty list

    cout << "List before appending: ";
    PrintCircular(head);            // should print "Empty list"

    // Append nodes to tail
    Append(&head, 10);              // list: 10
    Append(&head, 20);              // list: 10 -> 20
    Append(&head, 30);              // list: 10 -> 20 -> 30
    Append(&head, 40);              // list: 10 -> 20 -> 30 -> 40 -> (back to 10)

    cout << "List after appending: ";
    PrintCircular(head);            // prints: 10 20 30 40

    // Insert in between
    InsertAfterValue(head, 20, 25); // insert 25 after 20
    InsertAfterValue(head, 40, 45); // insert 45 after 40

    cout << "List after inserting in between: ";
    PrintCircular(head);            // prints: 10 20 25 30 40 45

    return 0;
}
