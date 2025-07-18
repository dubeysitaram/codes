// 07_constfunction.cpp

/*
area() and display() are const member functions.
They guarantee not to modify any member variables.
If you try to modify members inside a const function, you’ll get a compile-time error.
const functions can be called on const objects.
*/


#include <iostream>
using namespace std;

class Rectangle {
	int length, breadth;

public:
	Rectangle(int l, int b) : length(l), breadth(b) {}

	int area() const { // const member function
		return length * breadth;
	}

	void display() const { // const member function
		cout << "Length: " << length << ", Breadth: " << breadth << endl;
	}

	void setLength(int l) {
		length = l; // This is allowed (non-const function)
	}
};

int main() {
	Rectangle r(10, 5);
	r.display();          // Length: 10, Breadth: 5
	cout << r.area() << endl; // 50
	return 0;
}

#include <iostream>
using namespace std;

class Circle {
	int radius;

public:
	Circle(int r) : radius(r) {}

	int getRadius() const { // const function
		return radius;
	}

	void display() const { // const function
		cout << "Radius: " << radius << endl;
	}

	// void setRadius(int r) { radius = r; } // NOT allowed on const objects
};

int main() {
	const Circle c(10); // const object

	c.display();               // ✅ allowed
	cout << c.getRadius();     // ✅ allowed

	// c.setRadius(20);        // ❌ not allowed — would cause a compile-time error

	return 0;
}
/*
Const methods:
Can be called on both const and non-const objects.

Non-const methods:
Can only be called on non-const objects.
*/