#include <iostream>
using namespace std;

// Define a fixed size for the queue
#define SIZE 5

// Create a class for the Queue
class Queue {
private:
    int items[SIZE];  // Array to store queue elements
    int front;        // Points to the front element (the one to be removed next)
    int rear;         // Points to the last element (where new elements are added)

public:
    // Constructor: initialize front and rear as empty (-1)
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        // If front is -1 (no elements yet) OR front has moved past rear (all removed)
        return (front == -1 || front > rear);
    }

    // Function to check if the queue is full
    bool isFull() {
        // When rear reaches the last index (SIZE - 1), no more space left
        return (rear == SIZE - 1);
    }

    // Function to add (enqueue) an element at the rear
    void enqueue(int value) {
        if (isFull()) {
            // Stop if no space is available
            cout << "Queue is full (Overflow)\n";
            return;
        }

        // If queue was empty, set front to 0 (first element)
        if (front == -1)
            front = 0;

        // Move rear forward to the next index
        rear++;

        // Insert the new element at the rear position
        items[rear] = value;

        cout << value << " added to the queue\n";
    }

    // Function to remove (dequeue) an element from the front
    void dequeue() {
        if (isEmpty()) {
            // Stop if there are no elements to remove
            cout << "Queue is empty (Underflow)\n";
            return;
        }

        // Display the element being removed (the one at the front)
        cout << items[front] << " removed from the queue\n";

        // Move front forward to point to the next element in line
        front++;

        // If front goes beyond rear, it means all elements were removed
        // So reset both front and rear to -1 (empty queue again)
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Function to display all elements currently in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        // Loop through from front to rear and print elements
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

// Main program to test the queue
int main() {
    Queue q;  // Create a queue object

    q.enqueue(10);   // Add 10 to the queue
    q.enqueue(20);   // Add 20 to the queue
    q.enqueue(30);   // Add 30 to the queue

    q.display();     // Show current elements (10, 20, 30)

    q.dequeue();     // Remove the first element (10)
    q.display();     // Show remaining elements (20, 30)

    return 0;        // End of program
}


