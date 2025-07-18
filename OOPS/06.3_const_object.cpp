/*
Yes, when an object is declared as const, it can only call const member functions —
because only those functions guarantee not to modify the object's state.
*/

#include <iostream>
using namespace std;

class Book {
	int pages;

public:
	Book(int p) : pages(p) {}

	void setPages(int p) {
		pages = p;
	}

	int getPages() const { // const method
		return pages;
	}

	void display() const { // const method
		cout << "Pages: " << pages << endl;
	}
};

int main() {
	const Book b(100);   // const object

	b.display();         // ✅ OK — display() is const
	cout << b.getPages(); // ✅ OK — getPages() is const

	// b.setPages(200);  // ❌ Error — can't call non-const method on const object

	return 0;
}

/*

❓ Why this is done
Declaring an object const ensures read-only access:

Prevents accidental modification of the object.

Helps in defensive programming and code safety.

Allows passing objects to functions by const reference, ensuring no change.

*/