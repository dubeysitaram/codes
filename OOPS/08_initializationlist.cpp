// 07_initializationlist.cpp


#include <iostream>
using namespace std;

class Point {
	int x;
	int *y;
	int z;

public:
	// Constructor using initialization list
	Point(int _a, int _b, int _c) : x(_a), y(new int(_b)), z(_z) {
		cout << "x = " << x << ", y = " << y << endl;
	}
};

int main() {
	Point p(10, 20);
	return 0;
}


// -----------------------------------BENEFIT OF INITIALIZATION LIST------------------------------------------

/*
📌 Notes:

Uncommenting the second constructor or the assignment in updateX() will cause compilation errors.

This shows that const members must be initialized via an initialization list only and are immutable after that.
*/

#include <iostream>
using namespace std;

class Example {
	const int x;

public:
	// ✅ Correct: const member initialized in initialization list means x is assigned with value val
	Example(int val) : x(val) {
		cout << "Constructor with initializer list: x = " << x << endl;
	}

	// ❌ Uncommenting below constructor will cause compile-time error
	/*
	Example(int val) {
	    x = val; // ❌ Error: assignment of read-only (const) member
	}
	*/

	void updateX(int val) {
		// ❌ Error: cannot modify a const member in a normal function
		// x = val;
	}
};

int main() {
	Example e(10);
	// e.updateX(20); // ❌ Would cause error if updateX tries to modify x
	return 0;
}
