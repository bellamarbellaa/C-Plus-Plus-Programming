#include <iostream>
#include <string>
using namespace std;

class StackArray {
    string arr[5];       // fixed array size 5
    int top;             // index of top element

public:
    StackArray() : top(-1) {}

    bool isEmpty() {
        if (top == -1) {
            cout << "Stack is empty\n";  // print message
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top == 4) {
            cout << "Stack is full\n";   // print message
            return true;
        }
        return false;
    }

    void push(const string& song) {
        if (isFull())
            return;
        arr[++top] = song;
    }

    string pop() {
        if (isEmpty())
            return "";
        string popped_song = arr[top--];
        cout << "Popped song: " << popped_song << endl;
        return popped_song;
    }

    void print() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }
};

int main() {
    StackArray playlist1, playlist2;

    string songs1[4] = {"You Belong With Me", "Love Story", "Bejeweled", "Ready for it"}; // 4 songs inserted
    string songs2[5] = {"Lost Girls", "Sixteen", "This Is Me Trying", "Paper Rings", "Gorgeous"};

    for (int i = 0; i < 4; i++) {  // push 4 songs, stack not full yet
        playlist1.push(songs1[i]);
    }

    for (int i = 0; i < 5; i++) {
        playlist2.push(songs2[i]);
    }

    cout << "Playlist 1:\n";
    playlist1.print();

    cout << "\nPlaylist 2:\n";
    playlist2.print();

    // Pop 2 songs from playlist2 and push them to playlist1
    if (!playlist2.isEmpty()) {
        string popped_song1 = playlist2.pop();
        playlist1.push(popped_song1);  // 5th song for playlist1, should fill stack
    }
    if (!playlist2.isEmpty()) {
        string popped_song2 = playlist2.pop();  // tries to push 6th song, stack full message shown
        playlist1.push(popped_song2);
    }

    cout << "\nPlaylist 1 After 2 Songs Addition:\n";
    playlist1.print();

    cout << "\nPlaylist 2 After 2 Songs Removal:\n";
    playlist2.print();

    return 0;
}

