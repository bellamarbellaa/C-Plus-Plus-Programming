#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;        // node value
    Node* next;      // pointer to next node
    Node* prev;      // pointer to previous node

    // Constructor
    Node(int val = 0, Node* nextLoc = NULL, Node* prevLoc = NULL) {
        data = val;
        next = nextLoc;
        prev = prevLoc;
    }
};

/*--------------------------------------------
 Print list from head to tail
---------------------------------------------*/
void PrintForward(Node* head) {
    if (head == NULL) {
        cout << "(empty list)\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*--------------------------------------------
 Print list from tail to head
---------------------------------------------*/
void PrintBackward(Node* head) {
    if (head == NULL) {
        cout << "(empty list)\n";
        return;
    }

    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

/*--------------------------------------------
 Insert a new node at the FRONT (PushFront)
---------------------------------------------*/
void PushFront(Node** head_ref, int val) {
    Node* newNode = new Node(val);         // create new node
    if (*head_ref == NULL) {               // empty list
        *head_ref = newNode;
        return;
    }
    newNode->next = *head_ref;             // new node links to old head
    (*head_ref)->prev = newNode;           // old head points back to new node
    *head_ref = newNode;                   // update head
}

/*--------------------------------------------
 Append a new node at the END (Append)
---------------------------------------------*/
void Append(Node** head_ref, int val) {
    Node* newNode = new Node(val);
    if (*head_ref == NULL) {               // empty list
        *head_ref = newNode;
        return;
    }

    Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;                  // link last to new node
    newNode->prev = temp;                  // back link new node to last
}

/*--------------------------------------------
 Insert a new node AFTER a given node pointer
---------------------------------------------*/
void InsertAfter(Node** head_ref, Node* prevNode, int val) {
    if (prevNode == NULL) {
        cout << "InsertAfter error: prevNode is NULL.\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = prevNode->next;        // connect newNode forward
    newNode->prev = prevNode;              // link back to prevNode
    prevNode->next = newNode;              // link prevNode forward to newNode

    if (newNode->next != NULL)
        newNode->next->prev = newNode;     // fix successor's back link
}

/*--------------------------------------------
 Insert a new node BEFORE a given node pointer
---------------------------------------------*/
void InsertBefore(Node** head_ref, Node* nextNode, int val) {
    if (nextNode == NULL) {
        cout << "InsertBefore error: nextNode is NULL.\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = nextNode;              // new node points to nextNode
    newNode->prev = nextNode->prev;        // and back to nextNode's previous
    nextNode->prev = newNode;              // nextNode links back to newNode

    if (newNode->prev != NULL)
        newNode->prev->next = newNode;     // connect previous node forward
    else
        *head_ref = newNode;               // update head if inserted before head
}

/*--------------------------------------------
 Insert AFTER a node that has a specific value
---------------------------------------------*/
void InsertAfterValue(Node** head_ref, int targetValue, int valToInsert) {
    if (*head_ref == NULL) return;

    Node* cur = *head_ref;
    while (cur != NULL && cur->data != targetValue)
        cur = cur->next;

    if (cur == NULL) {
        cout << "InsertAfterValue: value " << targetValue << " not found.\n";
        return;
    }

    Node* newNode = new Node(valToInsert); // create new node
    newNode->next = cur->next;             // new node connects forward
    newNode->prev = cur;                   // new node links back to cur
    cur->next = newNode;                   // cur links forward to new node

    if (newNode->next != NULL)
        newNode->next->prev = newNode;     // fix next node's back link
}

/*--------------------------------------------
 Insert BEFORE a node that has a specific value
---------------------------------------------*/
void InsertBeforeValue(Node** head_ref, int targetValue, int valToInsert) {
    if (*head_ref == NULL) return;

    Node* cur = *head_ref;
    while (cur != NULL && cur->data != targetValue)
        cur = cur->next;

    if (cur == NULL) {
        cout << "InsertBeforeValue: value " << targetValue << " not found.\n";
        return;
    }

    Node* newNode = new Node(valToInsert);
    newNode->next = cur;                   // new node goes before cur
    newNode->prev = cur->prev;             // link back to cur's prev
    cur->prev = newNode;                   // link cur back to new node

    if (newNode->prev != NULL)
        newNode->prev->next = newNode;     // connect previous node
    else
        *head_ref = newNode;               // update head if before first
}

/*--------------------------------------------
 MAIN FUNCTION
---------------------------------------------*/
int main() {
    Node* head = NULL;

    // PushFront: add new nodes at the head
    PushFront(&head, 10);   // list: 10
    PushFront(&head, 20);   // list: 20 10
    PushFront(&head, 30);   // list: 30 20 10
    cout << "After PushFront: ";
    PrintForward(head);     // expected: 30 20 10

    // Append: add at tail
    Append(&head, 40);      // list: 30 20 10 40
    Append(&head, 50);      // list: 30 20 10 40 50
    cout << "After Append: ";
    PrintForward(head);     // expected: 30 20 10 40 50

    // InsertAfter: insert 25 after the second node
    InsertAfter(&head, head->next, 25);    // list: 30 20 25 10 40 50
    cout << "After InsertAfter(head->next,25): ";
    PrintForward(head);

    // InsertBeforeValue: insert 15 before node with value 10
    InsertBeforeValue(&head, 10, 15);      // list: 30 20 25 15 10 40 50
    cout << "After InsertBeforeValue(&head,10,15): ";
    PrintForward(head);

    // InsertAfterValue: insert 45 after node with value 40
    InsertAfterValue(&head, 40, 45);       // list: 30 20 25 15 10 40 45 50
    cout << "After InsertAfterValue(&head,40,45): ";
    PrintForward(head);

    // InsertBefore: insert before third node
    InsertBefore(&head, head->next->next, 35);         // list: 30 20 35 25 15 10 40 45 50
    cout << "After InsertBefore(&head,head,35): ";
    PrintForward(head);

    cout << "Backward traversal: ";
    PrintBackward(head);                   
    //50 45 40 10 15 25 35 20 30

    return 0;
}


