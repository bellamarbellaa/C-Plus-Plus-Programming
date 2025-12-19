#include <iostream>
using namespace std;

/*
 * Recursive function to print and calculate factorial
 * Parameters:
 *   factCounter - the current number in countdown (e.g., from N ? 1)
 *   factValue   - the accumulated product so far
 */
void PrintFactorial(int factCounter, int factValue) {
    // Base Case: stop recursion when factCounter == 1
    if (factCounter == 1) {
        cout << factCounter;  // Print the last number (1)
        cout << " = " << factValue << endl;  // Show the final result
        return;
    }

    // Recursive Case: multiply factValue by factCounter
    cout << factCounter << " * ";  // Print current step
    int nextValue = factValue * (factCounter - 1);  // Multiply for the next step

    // Recursive call: go to the next smaller number
    PrintFactorial(factCounter - 1, nextValue);
}

int main() {
    int userVal;

    // Ask user for a number
    cout << "Enter a number: ";
    cin >> userVal;

    // Display what we’re calculating
    cout << userVal << "! = ";

    // Start recursion from the user's number
    PrintFactorial(userVal, userVal);

    return 0;
}
