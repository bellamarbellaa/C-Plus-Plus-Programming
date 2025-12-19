#include <iostream>
using namespace std;

// Function to compute the Nth Fibonacci number recursively.
// F(n) = F(n-1) + F(n-2)
int Fibonacci(int n) {
    // 1. FIRST BASE CASE: F(0) = 0.
    if (n == 0) {
        return 0;
    } 
    // 2. SECOND BASE CASE: F(1) = 1.
    else if (n == 1) {
        return 1;
    } 
    // 3. RECURSIVE CASE: F(n) = F(n-1) + F(n-2).
    else {
        // The pattern is to compute the next number by adding the previous two numbers.
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main() {
    int n = 5; // Fixed for the example
    
    // Output the final result
    cout << "The Fibonacci number at position " << n << " is: " << Fibonacci(n) << endl;
    
    return 0;
}

