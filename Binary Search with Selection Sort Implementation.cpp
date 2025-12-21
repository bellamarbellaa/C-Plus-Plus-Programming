#include <iostream>
using namespace std;

//Step 1: Function to selection sort for an array of grades in ascending order
void selectionSort(float* grades, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (grades[j] < grades[minIdx]) {
                minIdx = j;
            }
        }
        //Then swap grades[i] and grades[minIdx]
        float temp = grades[i];
        grades[i] = grades[minIdx];
        grades[minIdx] = temp;
    }
}

//Step 2: Function to do binary search for a grade in sorted array
int binarySearch(float* grades, int size, float target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (grades[mid] == target)
            return mid; // found
        else if (grades[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

int main() {
    int size;
    cout << "Enter number of grades: ";
    cin >> size;

	//Step 3: Ask user for the grades entry
    float* grades = new float[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter grade #" << i + 1 << ": ";
        cin >> grades[i];
    }

    // Step 4: Sort grades before searching
    selectionSort(grades, size);

	//Step 5: Ask grade key to do binary search for
    float searchVal;
    cout << "Enter grade to search: ";
    cin >> searchVal;

	//Step 5: Display result of binary search
    int idx = binarySearch(grades, size, searchVal);
    if (idx != -1)
        cout << "Grade " << searchVal << " found at index " << idx << endl;
    else
        cout << "Grade " << searchVal << " not found.\n";

    delete[] grades;
    
    return 0;
}

