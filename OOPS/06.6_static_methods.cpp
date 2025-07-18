#include <iostream>
using namespace std;

class Calculator {
public:
	static int add(int a, int b);       // static method declaration
	static int multiply(int a, int b);  // another static method
};

// static method definition same as class name
int Calculator::add(int a, int b) {
	return a + b;
}

int Calculator::multiply(int a, int b) {
	return a * b;
}

int main() {
	// Calling static methods using class name
	cout << "Sum: " << Calculator::add(5, 3) << endl;
	cout << "Product: " << Calculator::multiply(5, 3) << endl;

	// You can call using object (allowed but not preferred)
	Calculator c;
	cout << "Again Sum: " << c.add(10, 20) << endl;

	return 0;
}
