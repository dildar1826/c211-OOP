#include <iostream>
using namespace std;

/* 
   ==================================================
   1. USING FUNCTIONS INSIDE STRUCTS
   ==================================================
   We can define member functions directly inside a struct 
   to perform operations using the struct's own data members.
*/
struct Box {
    int length;
    int width;

    /* 
       ==============================================
       3. PASSING A STRUCT TO A FUNCTION INSIDE ITSELF
       ==============================================
       The isLarger function takes another object of the 
       same struct type (Box) as a parameter to compare 
       it with the current object.
    */
    bool isLarger(Box otherBox) {
        int currentArea = length * width;
        int otherArea = otherBox.length * otherBox.width;

        return currentArea > otherArea;
    }
};

/* 
   ==================================================
   2. ACCESSING MEMBERS OF ONE STRUCT IN ANOTHER
   ==================================================
   The Test struct interacts with the Box struct by 
   accepting a Box object as a parameter in its function 
   and accessing its data members.
*/
/*struct Test {
    int multiplier;

    int calculateScaledArea(Box b) {
        // Accessing members of 'Box' via the passed object 'b'
        return (b.length * b.width) * multiplier;
    }
};

int main() {
    // Testing Concept 3: Member function taking an object of itself
    Box box1 = {10, 5};  // Area = 50
    Box box2 = {6, 6};   // Area = 36

    if (box1.isLarger(box2)) {
        cout << "box1 is larger than box2." << endl;
    } else {
        cout << "box1 is not larger than box2." << endl;
    }

    // Testing Concept 2: Passing an object of Box into Test's function
    Box myBox = {5, 4};
    Test t1;
    t1.multiplier = 3;

    int result = t1.calculateScaledArea(myBox);
    cout << "Scaled Area: " << result << endl; // (5 * 4) * 3 = 60

    return 0;
}*/
//======================= TASK #1===========================
class Rectangle {
private:
    int length;
    int width;

public:
    // Setter function with validation (must be greater than zero)
    void setLength(int l) {
        if (l > 0) 
            length = l;
        else {
            cout << "Invalid length! Must be greater than zero." << endl;
            length = 0;
        }
    }

    void setWidth(int w) {
        if (w > 0) {
            width = w;
        } else {
            cout << "Invalid width! Must be greater than zero." << endl;
            width = 0;
        }
    }

    // Getter functions
    int getLength() {
        return length;
    }

    int getWidth() {
        return width;
    }

    // Calculate area function
    int calculateArea() {
        return length * width;
    }

    // Calculate perimeter function
    int calculatePerimeter() {
        return 2 * (length + width);
    }

    // Predicate function to check if it's a square
    bool isSquare() {
        return length == width && length > 0;
    }
};

int main() {
    Rectangle rect;

    rect.setLength(10);
    rect.setWidth(10);

    cout << "Area: " << rect.calculateArea() << endl;
    cout << "Perimeter: " << rect.calculatePerimeter()<< endl;

    if (rect.isSquare()) {
        cout << "The rectangle is a square." << endl;
    } else {
        cout << "The rectangle is not a square." << endl;
    }

    return 0;
}

// this code (task1) is written using ai, because i accidentally deleted my code
