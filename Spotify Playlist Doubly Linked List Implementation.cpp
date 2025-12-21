#include <iostream>
#include <string>
using namespace std;

class SongNode {
private:
    string songName; //song title
    SongNode* nextNodePtr;    // Pointer to next song
    SongNode* prevNodePtr;    // Pointer to previous song

public:
    // Constructor
    SongNode(string name = "", SongNode* nextLoc = NULL, SongNode* prevLoc = NULL) {
        songName      = name;
        nextNodePtr   = nextLoc;
        prevNodePtr   = prevLoc;
    }

    // Insert 'nextLoc' immediately after 'this' node
    void InsertAfter(SongNode* nextLoc) {
        SongNode* tmpNext = nextNodePtr;      
        nextNodePtr = nextLoc;               
        nextLoc->prevNodePtr = this;         
        nextLoc->nextNodePtr = tmpNext;       
        if (tmpNext != NULL) {               
            tmpNext->prevNodePtr = nextLoc;  
        }
    }

    // PushHead: Updates the list head using a pointer to a pointer (**)
    static void PushHead(SongNode** headRef, const string& newSong) {
        SongNode* newNode = new SongNode(newSong);

        // 1. The new node points to the current head of the list.
        newNode->nextNodePtr = *headRef;          
        
        if (*headRef != NULL) {
            // 2. The old head's prev pointer is updated to point back to the new node.
            (*headRef)->prevNodePtr = newNode;
        }
        
        // 3. Update the original head pointer (headObj) to point to the new node.
        *headRef = newNode;
    }

    // Print list from head to tail
    static void PrintList(SongNode* headLoc) {
        cout << "\nPlaylist (forward):\n";
        SongNode* curr = headLoc;
        while (curr != NULL) {
            cout << curr->songName << endl;
            curr = curr->nextNodePtr;
        }
        cout << endl;
    }

    // Print list from tail to head
    static void PrintBackward(SongNode* tailLoc) {
        cout << "\nPlaylist (backward):\n";
        SongNode* curr = tailLoc;
        while (curr != NULL) {
            cout << curr->songName << endl;
            curr = curr->prevNodePtr;
        }
        cout << endl;
    }
};

int main() {
    // Initial list construction
    SongNode* node1 = new SongNode("Let It Go");
    SongNode* node2 = new SongNode("When Will My Life Begins");
    SongNode* node3 = new SongNode("For The First Time in Forever");

    node1->InsertAfter(node2);
    node2->InsertAfter(node3);

    SongNode* headObj = node1; // Head of list
    SongNode* tailObj = node3; // Tail of list

    cout << "Original Spotify Playlist:";
    SongNode::PrintList(headObj);
    SongNode::PrintBackward(tailObj);

    // Add new songs to the front
    string s1, s2;
    
    cout << "\nEnter a song to add to the front: ";
    getline(cin, s1); 
    // Call PushHead: passing the ADDRESS of the headObj pointer (&headObj)
    SongNode::PushHead(&headObj, s1); 

    cout << "Enter another song to add to the front: ";
    getline(cin, s2); 
    // Call PushHead: passing the ADDRESS of the headObj pointer (&headObj)
    SongNode::PushHead(&headObj, s2); 

    cout << "\nUpdated Spotify Playlist (forward)";
    SongNode::PrintList(headObj);

    // Reassign tail after pushing new songs 
    tailObj = headObj;
    while (tailObj->nextNodePtr != NULL) {
        tailObj = tailObj->nextNodePtr;
    }
    
	cout << "\nUpdated Spotify Playlist (backward): ";
    SongNode::PrintBackward(tailObj);
    
    // Memory cleanup
    SongNode* curr = headObj;
    SongNode* next = NULL;
    while (curr != NULL) {
        next = curr->nextNodePtr;
        delete curr; // Free the memory for the current node
        curr = next;
    }
    
    return 0;
}
