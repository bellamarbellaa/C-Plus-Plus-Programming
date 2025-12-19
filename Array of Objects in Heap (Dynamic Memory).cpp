#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int id;
    double gpa;

    // Default constructor (needed for array of objects)
    Student() {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
    }

    // Parameterized constructor
    Student(string studentName, int studentId, double studentGpa) {
        name = studentName;
        id = studentId;
        gpa = studentGpa;
    }
};

int main() {
    // Create an array of 3 students (objects) in Heap
    Student* arr = new Student[3];

    // Assign values to each element
    arr[0] = Student("Alice", 101, 3.75);
    arr[1] = Student("Bob", 102, 3.60);
    arr[2] = Student("Charlie", 103, 3.90);

    // Display the array
    for (int i = 0; i < 3; i++) {
        cout << "Student " << i + 1
             << " has a name of " << arr[i].name
             << ", an ID of " << arr[i].id
             << ", and a GPA of " << arr[i].gpa
             << endl;
    }

    // Free heap memory
    delete[] arr;

    return 0;
}

