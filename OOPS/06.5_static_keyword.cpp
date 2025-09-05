// 06.5_static_keyword.cpp

/*
🔷 Explanation of static Keyword in OOP (C++)

🔸 What is static?
The static keyword in OOP (in C++) can be used:

With data members – to make them class-level variables.

With member functions – to make them class-level functions.

In functions – to preserve the value of local variables across function calls.

🔹 1. Static Data Members
✅ Meaning:
A static data member is shared among all objects of the class.
It is not dependent on any specific object.

✅ Properties:
Only one copy exists, regardless of the number of objects.

Can be accessed using the class name directly.

Needs to be defined outside the class.

🔹 2. Static Member Functions
✅ Meaning:
A static function belongs to the class, not any particular object.

✅ Properties:
Can be called using class name.

Cannot access non-static data members directly.

Can only access static data members and other static functions.

🔹 3. Static Local Variables
✅ Meaning:
When used inside a function, the variable retains its value between calls.



💡 How to Explain in Interview:

"In C++, static allows members to belong to the class rather than individual objects.
A static data member is shared among all instances,
which is useful for tracking common properties like object count. Static functions can be called without an object, 
but they can only access other static members. Also, inside a function,
static local variable retains its value across function calls,making it suitable for counting or caching purposes.

*/

#include <iostream>
using namespace std;

class Counter {
private:
	int id;                          // Non-static data member
	static int count;               // Static data member (shared)

public:
	Counter() {
		count++;
		id = count;
	}

	void display() {
		cout << "Object ID: " << id << ", Total Count: " << count << endl;
	}

	static void showCount() {
		cout << "Total objects created: " << count << endl;
		// cout << id; ❌ Error: Cannot access non-static members
	}

	void staticLocalExample() {
		static int callCount = 0; // static local variable
		callCount++;
		cout << "This function is called " << callCount << " times for object ID " << id << endl;
	}
};

// Define static member outside the class
int Counter::count = 0;

int main() {
	Counter::showCount(); // Before any object

	Counter a, b;
	a.display();
	b.display();

	Counter::showCount(); // After creating 2 objects

	a.staticLocalExample();
	a.staticLocalExample();

	b.staticLocalExample();
	b.staticLocalExample();

	return 0;
}
  