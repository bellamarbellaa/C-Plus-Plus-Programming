#include <iostream>
using namespace std;

//Node class to represent each element in the list
class Node {
public:
    int data;       //store the data value of node
    Node* next;     //pointer to next node in the list

    //Constructor: initialize data and pointer
    Node(int val = 0) {
        data = val;
        next = NULL;
    }

    //Insert a node directly after this node
    void InsertAfter(Node* nodeLoc) {
        nodeLoc->next = this->next;  //new node points to what current node was pointing to
        this->next = nodeLoc;        //current node points to the new node
    }
};

/*--------------------------------------------
 Function to print a circular linked list
---------------------------------------------*/
void PrintCircular(Node* head) {
    //If the linked list is empty, exit
    if (head == NULL) {
        cout << "(empty list)\n";
        return;
    }

    Node* temp = head;
    /*Use do-while loop to ensure at least the head node is printed,
      and stop when we reach the head again (circular nature)*/
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

/*--------------------------------------------
 Function to push (insert) a node to the front 
 of a circular linked list
---------------------------------------------*/
//Use ** pass-by-pointer so we can modify the original head pointer
void PushFrontCircular(Node** head_ref, int val) {
    //Create a new node with the given data
    Node* newNode = new Node(val);

    //If the list is empty, make new node point to itself
    if (*head_ref == NULL) {
        newNode->next = newNode;     //the next of first node is itself
        *head_ref = newNode;         //update head pointer
        return;
    }

    //Otherwise, find the last node (whose next points to head)
    Node* tail = *head_ref;
    while (tail->next != *head_ref) {
        tail = tail->next;
    }

    //New node's next points to old head
    newNode->next = *head_ref;

    //Last node now points to new node
    tail->next = newNode;

    //Update head to the new node
    *head_ref = newNode;
}

/*--------------------------------------------
 MAIN FUNCTION
---------------------------------------------*/
int main() {
    //Declare a pointer for head and initialize it to NULL
    Node* head = NULL;

    cout << "Before pushing, head = " << head << endl;

    //Add new nodes to the front of the circular linked list
    PushFrontCircular(&head, 7); //list: 7
    PushFrontCircular(&head, 6); //list: 6 7
    PushFrontCircular(&head, 5); //list: 5 6 7
    PushFrontCircular(&head, 4); //list: 4 5 6 7

    cout << "After pushing, head = " << head->data << endl;

    //Print all nodes in the circular linked list
    cout << "Circular Linked List: ";
    PrintCircular(head);

    return 0;
}


