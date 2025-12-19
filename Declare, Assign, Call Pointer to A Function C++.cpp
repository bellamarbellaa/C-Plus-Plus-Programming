#include <iostream>
using namespace std;

//Declare and define two functions
int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}

int main() {
	//Declare and assign fp pointer. fp is a pointer to a function taking (int, int) and returning int
	int (*fp) (int, int);
	
	//Call function using pointer
	fp = add;                  // function name “decays” to its address
    cout << fp(7, 5) << "\n";  // 12  (calls add)
	
	//Call function using pointer
    fp = sub;                  // point to a different function
    cout << fp(7, 5) << "\n";  // 2   (calls sub)
    
    return 0;
}
	

	
