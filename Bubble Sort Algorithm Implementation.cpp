#include <iostream>
using namespace std;

// Bubble Sort in Ascending Order
// The outer loop controls the number of passes. The inner loop compares adjacent elements.
// If the left element is greater than the right, swap them.
void bubbleSortAscending(int a[], int length) {
    bool swapped;
    for (int i = 0; i < length - 1; i++) {
        swapped = false; // Track if any swap happened in this pass
        for (int j = 0; j < length - 1 - i; j++) {
            if (a[j] > a[j + 1]) { // Compare adjacent elements
                // Swap if elements are in the wrong order
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        // If no swaps happened in this pass, the array is already sorted
        if (!swapped)
            break;
    }
}

// Bubble Sort in Descending Order
// The only change: swap if left element is less than right element.
void bubbleSortDescending(int a[], int length) {
    bool swapped;
    for (int i = 0; i < length - 1; i++) {
        swapped = false; 
        for (int j = 0; j < length - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Function to print the elements of the array
void printArray(int a[], int length) {
    for(int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {4,8,1,5,9,0,2,7,3,6};
    int length = 10;

    // Call bubble sort (ascending)
    bubbleSortAscending(a, length);

    cout << "Sorted in ascending order: ";
    printArray(a, length);
    
    // Call bubble sort (descending)
    bubbleSortDescending(a, length);
    
    cout << "Sorted in descending order: "; 
    printArray(a, length);

    return 0;
}

