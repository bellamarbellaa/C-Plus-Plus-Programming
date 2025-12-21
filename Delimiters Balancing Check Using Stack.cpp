#include <iostream>  // For input and output streams
#include <stack>     // For using the stack data structure
#include <string>    // For using the std::string type

using namespace std;

// Function to check if two delimiters are matching pairs
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

// Function to check if all delimiters in the expression are balanced
bool areDelimitersBalanced(const string& expression) {
    stack<char> s;  // Stack to keep track of opening delimiters
    // Iterate over each character in the expression
    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        // If the character is an opening delimiter, push it onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        // If the character is a closing delimiter
        else if (ch == ')' || ch == ']' || ch == '}') {
            // If stack is empty, no opening delimiter for this closing one
            if (s.empty()) {
                return false;
            }
            // Get the top element (most recent opening delimiter)
            char top = s.top();
            s.pop();
            // Check if the top element matches the current closing delimiter
            if (!isMatchingPair(top, ch)) {
                return false; // Delimiters do not match
            }
        }
    }
    // If stack is empty, all delimiters matched; otherwise, not balanced
    return s.empty();
}

int main() {
    // Test cases to verify delimiter balancing
    string test1 = "{[()]}";       // Balanced delimiters
    string test2 = "{[(])}";       // Not balanced delimiters
    string test3 = "{{[[(())]]}}"; // Balanced delimiters

    cout << "Test 1: " << (areDelimitersBalanced(test1) ? "Balanced" : "Not Balanced") << endl;
    cout << "Test 2: " << (areDelimitersBalanced(test2) ? "Balanced" : "Not Balanced") << endl;
    cout << "Test 3: " << (areDelimitersBalanced(test3) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}


