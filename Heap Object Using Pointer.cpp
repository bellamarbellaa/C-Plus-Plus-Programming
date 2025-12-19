#include <iostream>
using namespace std;

class Point {
	public:
	int xValue = 0;
	
	Point(int x) {
		xValue = x;
	}
};

int main() {
    Point* p1 = new Point(42);  //heap object
    cout << "X value of p1 is: " << p1->xValue << endl;
    delete p1;  //must delete to free heap memory
    return 0;
}
