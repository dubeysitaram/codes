// 07_mutable_keyword.cpp
#include <iostream>
using namespace std;

class Demo {
	int x;
	mutable int counter; // can be modified even in const functions

public:
	Demo(int val) : x(val), counter(0) {}

	void show() const {
		counter++; // allowed because 'counter' is mutable
		cout << "x = " << x << ", counter = " << counter << endl;
	}
};

int main() {
	Demo d(5);
	d.show(); // x = 5, counter = 1
	d.show(); // x = 5, counter = 2
	return 0;
}
