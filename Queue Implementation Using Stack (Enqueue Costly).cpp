#include <iostream>
#include <stack>
using namespace std;

class QueueWithStackEnqueueCostly {
private:
    stack<int> s1, s2; // s1 will hold the queue, s2 is for transfer

public:
    // Add a new element to the queue (costly)
    void enqueue(int x) {
        // First move everything in s1 to s2, reversing order
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Place the new element into empty s1
        s1.push(x);
        // Move everything back from s2 to s1 so front is still bottom of s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Remove and return the front element
    int dequeue() {
        if (s1.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int val = s1.top();  // The oldest element is always on top
        s1.pop();
        return val;
    }

    // Show the current front without removing
    int front() {
        if (s1.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return s1.top();
    }

    // Return true if the queue has no elements
    bool empty() {
        return s1.empty();
    }
};

int main() {
    QueueWithStackEnqueueCostly q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Front: " << q.front() << endl; // 20

    q.enqueue(40);
    cout << "Dequeue: " << q.dequeue() << endl; // 20
    cout << "Dequeue: " << q.dequeue() << endl; // 30
    cout << "Dequeue: " << q.dequeue() << endl; // 40

    if (q.empty()) {
        cout << "Queue is now empty\n";
    }

    return 0;
}

