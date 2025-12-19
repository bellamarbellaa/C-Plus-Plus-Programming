#include <iostream>
using namespace std;

int main() {
    // Declare a pointer to int
    int *arr;

    // Dynamically allocate memory on the heap for an array of 5 integers
    arr = new int[5];
    
    // Initialize the array elements with values 1, 2, 3, 4, 5
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;   // assign values to each index
    }
    
    // Print the array elements
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";  // display each element
        // *(arr+1) is another way to dereference the array using its pointer
    }
    
    cout << endl; // print a newline for better formatting

    // Free the memory allocated on the heap (avoid memory leaks)
    delete[] arr;
    
    return 0;  // end of program
}
