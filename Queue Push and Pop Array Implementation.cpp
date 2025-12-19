#include <iostream>
using namespace std;

#define MAX 5  // maximum capacity of the queue

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Add element to queue
    void push(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << x << " added to queue." << endl;
    }

    // Remove element from queue
    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;
        front++;
        if (front > rear) front = rear = -1; // reset when empty
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Get size
    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.pop();
    q.pop();

    cout << "Front element after pops: " << q.getFront() << endl;
    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

