/*
✅ inline static in C++17+
🔹 Purpose:
Allows you to define and initialize static data members inside the class.
No need to define it outside using ClassName::variable.

🔸 Syntax:

class Counter {
public:
    inline static int count = 0; // Definition + Initialization inside the class
};

*/

// full code usage

#include <iostream>
using namespace std;

class Counter {
public:
	inline static int count = 0; // declared inside the class

	Counter() {
		count++;
	}

	static void showCount() {
		cout << "Total objects: " << count << endl;
	}
};

int main() {
	Counter a, b, c; 
	Counter::showCount();  // Output: Total objects: 3
	return 0;
}
