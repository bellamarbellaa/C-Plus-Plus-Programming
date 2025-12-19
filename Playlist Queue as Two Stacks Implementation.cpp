#include <iostream>
#include <stack>
#include <string>
using namespace std;

// This is class for queue implemented using two stacks.
// Enqueue (push) is O(1) efficient.
// Dequeue (pop) is costly O(n) when transferring elements.
class QueueUsingStacks {
    stack<string> s1, s2;  // Two stacks to simulate queue behavior

public:
    // Add a song to the queue (enqueue) - O(1)
    void enqueue(const string& song) {
        s1.push(song);
    }

    // Remove and return the earliest added song (dequeue) - costly O(n) only when s2 empty
    string dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty\n";
                return "";
            }
            // Transfer all elements from s1 to s2, reversing order
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        string dequeued_song = s2.top();
        cout << "Dequeued song: " << dequeued_song << endl;
        s2.pop();
        return dequeued_song;
    }

    // Check if queue is empty
    bool isEmpty() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return true;
        }
        return false;
    }

    // Print the queue from front to back
    void print() {
        // Print elements in s2 from top to bottom (front segment)
        stack<string> temp_s2 = s2;
        while (!temp_s2.empty()) {
            cout << temp_s2.top() << endl;
            temp_s2.pop();
        }

        // Print elements in s1 from bottom to top (rear segment)
        stack<string> temp_s1;
        while (!s1.empty()) {
            temp_s1.push(s1.top());
            s1.pop();
        }
        while (!temp_s1.empty()) {
            cout << temp_s1.top() << endl;
            s1.push(temp_s1.top());  // restore s1
            temp_s1.pop();
        }
    }
};

int main() {
    QueueUsingStacks playlist1, playlist2;

    string songs1[5] = {"You Belong With Me", "Love Story", "Bejeweled", "Ready for it", "Girlfriend"};
    string songs2[5] = {"Lost Girls", "Sixteen", "This Is Me Trying", "Paper Rings", "Gorgeous"};

    for (int i = 0; i < 5; i++)
        playlist1.enqueue(songs1[i]);

    for (int i = 0; i < 5; i++)
        playlist2.enqueue(songs2[i]);

    cout << "Playlist 1:\n";
    playlist1.print();

    cout << "\nPlaylist 2:\n";
    playlist2.print();

    // Dequeue 2 songs from playlist2 and enqueue to playlist1
    if (!playlist2.isEmpty()) {
        string dequeued_song1 = playlist2.dequeue();
        playlist1.enqueue(dequeued_song1);
    }
    if (!playlist2.isEmpty()) {
        string dequeued_song2 = playlist2.dequeue();
        playlist1.enqueue(dequeued_song2);
    }

    cout << "\nPlaylist 1 After 2 Songs Addition:\n";
    playlist1.print();

    cout << "\nPlaylist 2 After 2 Songs Removal:\n";
    playlist2.print();

    return 0;
}

