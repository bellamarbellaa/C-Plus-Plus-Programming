#include <iostream>
#include <stack>
using namespace std;

class QueueWithStackDequeueCostly {
private:
    stack<int> s1, s2; // s1 for enqueue, s2 for dequeue

public:
    // Add new element to the queue (easy, just push to s1)
    void enqueue(int x) {
        s1.push(x);
    }

    // Remove and return the front element (costly)
    int dequeue() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        // If s2 has no elements, move everything from s1 to s2 to reverse
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    // Show what is at the front of the queue
    int front() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        // Fill s2 with reversed elements if needed
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Return true if queue has no elements
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueWithStackDequeueCostly q;

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

