#include <iostream>
using namespace std;

class IntNode {
	public:
		IntNode(int dataInit, IntNode* nextLoc); // constructor: initializes node with data and pointer to next node
		void InsertAfter(IntNode* nodeLoc);     // insert a new node right after the current node
		IntNode* GetNext();                     // return the pointer to the next node
		void PrintNodeData();                   // print the data stored in this node
	
	private:
		int dataVal;        // stores the data value of this node
		IntNode* nextNodePtr; // pointer to the next node in the list
};

// Constructor: sets data value and pointer to the next node
IntNode:: IntNode(int dataInit = 0, IntNode* nextLoc = NULL) { 
//the default values of 0 and NULL makes the arguments are optional (useful especially for nextLoc pointer)
	this->dataVal = dataInit;
	this->nextNodePtr = nextLoc;
}

//InsertAfter: link a new node directly after the current node
void IntNode::InsertAfter(IntNode* nextLoc) {
    IntNode* tmpNext = this->nextNodePtr; //Temporarily save the current node's next pointer
    this->nextNodePtr = nextLoc;          //Point the current node's next pointer to the new node
    nextLoc->nextNodePtr = tmpNext;       //Point the new node's next pointer to the old node's next node
}

//Print this node's data value
void IntNode::PrintNodeData() {
    cout << this->dataVal << endl;
}

//Return the pointer to the next node
IntNode* IntNode::GetNext() {
    return this->nextNodePtr;
}

int main() {
	//Declare pointers for 4 node objects
	IntNode* headObj = NULL;
	IntNode* nodeObj1 = NULL;
	IntNode* nodeObj2 = NULL;
	IntNode* nodeObj3 = NULL;
	
	//Create nodes on heap memory and assign their pointers
    headObj  = new IntNode(-1); // dummy head (placeholder)
    nodeObj1 = new IntNode(555);
    nodeObj2 = new IntNode(999);
    nodeObj3 = new IntNode(777);
	
	//Link nodes together using InsertAfter
    headObj->InsertAfter(nodeObj1);  // -1 -> 555
    nodeObj1->InsertAfter(nodeObj2); // -1 -> 555 -> 999
    nodeObj2->InsertAfter(nodeObj3); // -1 -> 555 -> 999 -> 777
	
	//Traverse through the list and print all node values
    IntNode* currObj = headObj;
    while (currObj != NULL) {
        currObj->PrintNodeData();
        currObj = currObj->GetNext();
    }
}

