#include <iostream>
using namespace std;

// Step 1: Linear search to find target grade index in unsorted or sorted array
int linearSearch(float* grades, int size, float target) {
    for (int i = 0; i < size; i++) {
        if (grades[i] == target)
            return i; 
    }
    return -1; //if not found
}

int main() {
	int size;
    cout << "Enter number of grades: ";
    cin >> size;

	//Step 2: Ask user for grades entry
    float* grades = new float[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter grade #" << i + 1 << ": ";
        cin >> grades[i];
    }
	
	//Step 3: Ask user for search key
    float searchVal;
    cout << "Enter grade to search: ";
    cin >> searchVal;

	//Step 4: Display result of linear search
    int idx = linearSearch(grades, size, searchVal);
    if (idx != -1)
        cout << "Grade " << searchVal << " found at index " << idx << endl;
    else
        cout << "Grade " << searchVal << " not found." << endl;

    delete[] grades;
    return 0;
}
