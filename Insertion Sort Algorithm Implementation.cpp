#include <iostream>
using namespace std;

// Insertion Sort - Ascending Order
void insertionSortAscending(int a[], int length) {
    for (int i = 1; i < length; i++) {
        int key = a[i];  // Element to be inserted
        int j = i - 1;

        // Move elements of a[0..i-1] that are greater than key one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;  // Insert key at the correct position
    }
}

// Insertion Sort - Descending Order
void insertionSortDescending(int a[], int length) {
    for (int i = 1; i < length; i++) {
        int key = a[i];  // Element to be inserted
        int j = i - 1;

        // Move elements of a[0..i-1] that are less than key one position ahead
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;  // Insert key at the correct position
    }
}

//Function to print array elements
void printArray(int a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {2, 4, 7, 8, 8, 1, 9, 3};
    int length = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    printArray(a, length);

    insertionSortAscending(a, length);
    cout << "Sorted array in ascending order: ";
    printArray(a, length);

    insertionSortDescending(a, length);
    cout << "Sorted array in descending order: ";
    printArray(a, length);

    return 0;
}


