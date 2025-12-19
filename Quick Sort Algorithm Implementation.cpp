#include <iostream>
#include <utility> 
using namespace std;

// Function prototypes
void quicksort_ascending(int array[], int low, int high);
void quicksort_descending(int array[], int low, int high);
int partition_ascending(int array[], int low, int high);
int partition_descending(int array[], int low, int high);

int main() {
    int a[] = {10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
    int length = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;

    // Sort ascending
    quicksort_ascending(a, 0, length - 1);

    cout << "Sorted ascending: ";
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;

    // Sort descending
    quicksort_descending(a, 0, length - 1);

    cout << "Sorted descending: ";
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

// Quick Sort for ascending
void quicksort_ascending(int array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition_ascending(array, low, high);
        quicksort_ascending(array, low, pivot_index - 1);
        quicksort_ascending(array, pivot_index + 1, high);
    }
}

// Partition for ascending order
int partition_ascending(int array[], int low, int high) {
    int pivot_value = array[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot_value) {
            swap(array[i], array[j]);
            i++;
        }
    }

    swap(array[i], array[high]);
    return i;
}

// Quick Sort for descending
void quicksort_descending(int array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition_descending(array, low, high);
        quicksort_descending(array, low, pivot_index - 1);
        quicksort_descending(array, pivot_index + 1, high);
    }
}

// Partition for descending order
int partition_descending(int array[], int low, int high) {
    int pivot_value = array[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] > pivot_value) {
            swap(array[i], array[j]);
            i++;
        }
    }

    swap(array[i], array[high]);
    return i;
}

