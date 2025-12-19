#include <iostream>
#include <string>
using namespace std;

class IntNode {
private:
    string dataVal;
    IntNode* nextNodePtr;

public:
    //Constructor to initialize a new node 
    IntNode(string song = 0, IntNode* nextLoc = NULL) {
        this->dataVal = song;
        this->nextNodePtr = nextLoc;
    }

    //PushHead: insert a new data value after the current's head 
    void PushHead(IntNode* headLoc,string newData) {
    	//*1) create a new node in memory and assign it the pointer newNode
        IntNode* newNode = new IntNode(newData);
        //*2) points the new node's next pointer to the node after head node
        newNode->nextNodePtr = headLoc->nextNodePtr; 
        /*3) points the head next pointer to the newNode, 
		making newNode comes before first node*/
        headLoc->nextNodePtr = newNode;
    }

    //InsertAfter: create the linked list of nodes in the first place
    void InsertAfter(IntNode* nextLoc) {
        IntNode* tmpNext = this->nextNodePtr;
        this->nextNodePtr = nextLoc;
        nextLoc->nextNodePtr = tmpNext;
    }

    //Print the full list except the headObj with placeholder value of -1
    void PrintList(IntNode* headLoc) {
        IntNode* currObj = headLoc->nextNodePtr;
        while (currObj != NULL) {
            cout << currObj->dataVal << endl;
            currObj = currObj->nextNodePtr;
        }
        cout << endl;
    }
    
};

int main() {
    IntNode* headObj = new IntNode("Test"); //create the head node

    //Build Original SpotifyList
    IntNode* node1 = new IntNode("Let It Go");
    IntNode* node2 = new IntNode("When Will My Life Begins");
    IntNode* node3 = new IntNode("For The First Time In Forever");

    headObj->InsertAfter(node1);  
    node1->InsertAfter(node2);   
    node2->InsertAfter(node3);    

    cout << "Original Spotify List: ";
    headObj->PrintList(headObj);  

    //Use PushHead to shift a new nodes to the front
    headObj->PushHead(headObj, "Try Everything");
    headObj->PushHead(headObj, "Lead The Way");
    headObj->PushHead(headObj, "Build A Snowman");

    cout << "New Spotify with Updated Songs: ";
    headObj->PrintList(headObj);  

    return 0;
}

