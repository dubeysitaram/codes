// 09.2_copyconstructor(deep).cpp

#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
public:
	Person(const char* n) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	// Custom copy constructor (deep copy)
	Person(const Person &p) {
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}

	void display() {
		cout << "Name: " << name << endl;
	}

	~Person() {
		delete[] name;
	}
};

int main() {
	Person p1("Sitaram");
	Person p2 = p1; // Custom copy constructor

	p1.display();
	p2.display();
	return 0;
}
