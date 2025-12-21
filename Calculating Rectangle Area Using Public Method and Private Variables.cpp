#include <iostream>
using namespace std;

class Rectangle {
    int width, height;   // private data members (hidden from outside)

public:
    // ? Setter sets values of private members
    void setValues(int w, int h) {
        width = w;
        height = h;
    }

    //Getter for width
    int getWidth() {
        return width;   // returns private member width
    }

    //Getter for height
    int getHeight() {
        return height;  // returns private member height
    }

    //Calculation Public Method
    int area() {
        return width * height;
    }
};

int main() {
    Rectangle rect;

    //Use setter to assign values because
    //data members width and height are private.
    //Instead, we use the public method setValues()
    rect.setValues(3, 4);

    //Use getters to access and display private data
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;

    // Use the public function area() to compute result
    cout << "Area of the rectangle is: " << rect.area() << endl;

    return 0;
}
