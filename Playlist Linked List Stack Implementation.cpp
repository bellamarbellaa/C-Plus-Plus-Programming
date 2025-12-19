#include <iostream>
#include <string>
using namespace std;

// This is class for a single song node in the playlist stack
class SongNode {
public:
    string data;        // song name
    SongNode* next;     // pointer to next song in stack

    SongNode(const string& song) : data(song), next(NULL) {}  // constructor
};

// This is class for the playlist stack implemented as linked list
class StackLinkedList {
    SongNode* top;      // pointer to top song in stack
public:
    StackLinkedList() : top(NULL) {}  // constructor initializes empty stack

    // Adds a song on top of the playlist stack
    void push(const string& song) {
        SongNode* newNode = new SongNode(song);  // create new song node
        newNode->next = top;                      // new node points to current top
        top = newNode;                            // new node becomes top
    }

    // Removes and returns the top song from playlist stack
    string pop() {
        if (top == NULL) {                        // if stack is empty
            cout << "Stack is empty\n";          // print message
            return "";
        }
        SongNode* temp = top;                     // temp pointer to current top
        string popped_song = top->data;           // save song name
        cout << "Popped song: " << popped_song << endl;
        top = top->next;                          // move top to next song
        delete temp;                              // free old top node
        return popped_song;                       // return popped song
    }

    // Checks if playlist stack is empty
    bool isEmpty() {
        if (top == NULL) {
            cout << "Stack is empty\n";          // print message if empty
            return true;
        }
        return false;
    }

    // Prints all songs in the playlist stack from top to bottom
    void print() {
        SongNode* temp = top;                     // temp pointer to traverse
        while (temp != NULL) {
            cout << temp->data << endl;           // print current song
            temp = temp->next;                     // move to next song
        }
    }
};

int main() {
    StackLinkedList playlist1, playlist2;

    // Array of 5 songs to init playlist1 stack
    string songs1[5] = {"You Belong With Me", "Love Story", "Bejeweled", "Ready for it", "Girlfriend"};
    // Array of 5 songs to init playlist2 stack
    string songs2[5] = {"Lost Girls", "Sixteen", "This Is Me Trying", "Paper Rings", "Gorgeous"};

    // Push songs onto playlist1 stack
    for (int i = 0; i < 5; i++)
        playlist1.push(songs1[i]);

    // Push songs onto playlist2 stack
    for (int i = 0; i < 5; i++)
        playlist2.push(songs2[i]);

    cout << "Playlist 1:\n";
    playlist1.print();

    cout << "\nPlaylist 2:\n";
    playlist2.print();

    // Pop 2 songs from playlist2 and push them to playlist1
    if (!playlist2.isEmpty()) {
        string popped_song1 = playlist2.pop();
        playlist1.push(popped_song1);
    }
    if (!playlist2.isEmpty()) {
        string popped_song2 = playlist2.pop();
        playlist1.push(popped_song2);
    }

    cout << "\nPlaylist 1 After 2 Songs Addition:\n";
    playlist1.print();

    cout << "\nPlaylist 2 After 2 Songs Removal:\n";
    playlist2.print();

    return 0;
}

