#include <iostream>
#include <cstring> // Necessary for all C-style string functions

using namespace std;

int main() {
	// Declare a pointer and allocate a char array of size 50 to that pointer
	char* heapString = new char[50];
    char* searchPtr = NULL; 
	
	// Copy initial text into it (using strcpy)
	strcpy(heapString, "Data Structures and Algorithms");
	
	cout << "The current string is: " << heapString << endl;
    
    // strlen: Show the current length
    cout << "Length of string is: " << strlen(heapString) << endl;
	
	// Concatenate more text (using strcat)
    char suffix[] = " are fun.";
	strcat(heapString, suffix);
	cout << "Concatenated string is: " << heapString << endl;

    cout << "\n" << endl;

    // strchr: Search for the first occurrence of a single character
    char search_char = 'S';
    searchPtr = strchr(heapString, search_char);
    
    if (searchPtr != NULL) {
        cout << "strchr: Character '" << search_char << "' found at index: " 
             << (searchPtr - heapString) << endl;
    }
	
    // strstr: Search for the first occurrence of an entire SUBSTRING
    char substring[] = "Algorithms";
    searchPtr = strstr(heapString, substring);
    
    if (searchPtr != NULL) {
        cout << "strstr: Substring \"" << substring << "\" found starting at index: " 
             << (searchPtr - heapString) << endl;
    } else {
        cout << "strstr: Substring was not found." << endl;
    }
	
    cout << "\n" << endl;
    
	// Compare strings (using strcmp)
    // The literal string doesn't match the final heapString, so this prints "Do not match"
	if(strcmp(heapString, "Data Structures") == 0) {
		cout << "strcmp: Strings match!" << endl;
	} else {
		cout << "strcmp: Strings do not match" << endl;
	}
	
	// Clean up the dynamic memory
	delete[] heapString;
	
	return 0;
}

