#include <iostream>
using namespace std;

int main() {
	// Declare a pointer to a string literal
	const char *foo = "hello";
	
	// Print the string using the pointer
	cout << "String literal: " << foo << endl;
	
	// Access characters one by one using array notation
	cout << "Using array notation: " << endl;
	for (int i = 0; foo[i] != '\0'; i++) {
		cout << "foo[" << i << "] = " << foo[i] << endl;
	}
	
	//Access characters one by one using pointer arithmetic
	cout << "Using pointer arithmetic: " << endl;
	for (int i = 0; *(foo + i) != '\0'; i++) {
		cout << "foo[" << i << "] = " << foo[i] << endl;
	}
	
	 //Example: Access the 5th character ('o')
    cout << "5th character (foo[4] or *(foo+4)) = " << foo[4] << endl;
    
    return 0;
}
