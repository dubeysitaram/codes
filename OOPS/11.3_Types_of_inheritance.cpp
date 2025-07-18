// ✅ 1. Single Inheritance
#include <iostream>
using namespace std;

class A {
public:
	void displayA() {
		cout << "Class A\n";
	}
};

class B : public A {
public:
	void displayB() {
		cout << "Class B (Single Inheritance)\n";
	}
};


// ✅ 2. Multiple Inheritance

class X {
public:
	void displayX() {
		cout << "Class X\n";
	}
};

class Y {
public:
	void displayY() {
		cout << "Class Y\n";
	}
};

class Z : public X, public Y {
public:
	void displayZ() {
		cout << "Class Z (Multiple Inheritance)\n";
	}
};

// ✅ 3. Multilevel Inheritance

class P {
public:
	void displayP() {
		cout << "Class P\n";
	}
};

class Q : public P {
public:
	void displayQ() {
		cout << "Class Q\n";
	}
};

class R : public Q {
public:
	void displayR() {
		cout << "Class R (Multilevel Inheritance)\n";
	}
};

// ✅ 4. Hierarchical Inheritance

class Base {
public:
	void displayBase() {
		cout << "Base Class\n";
	}
};

class Child1 : public Base {
public:
	void displayChild1() {
		cout << "Child1 (Hierarchical Inheritance)\n";
	}
};

class Child2 : public Base {
public:
	void displayChild2() {
		cout << "Child2 (Hierarchical Inheritance)\n";
	}
};

// ✅ 5. Hybrid Inheritance (Multiple + Multilevel)

class A1 {
public:
	void showA1() {
		cout << "A1\n";
	}
};

class A2 {
public:
	void showA2() {
		cout << "A2\n";
	}
};

class A3 : public A1, public A2 {
public:
	void showA3() {
		cout << "A3 (Multiple)\n";
	}
};

class A4 : public A3 {
public:
	void showA4() {
		cout << "A4 (Hybrid)\n";
	}
};

int main() {
	B b;
	b.displayA();
	b.displayB();

	Z z;
	z.displayX();
	z.displayY();
	z.displayZ();

	R r;
	r.displayP();
	r.displayQ();
	r.displayR();

	Child1 c1;
	c1.displayBase();
	c1.displayChild1();

	Child2 c2;
	c2.displayBase();
	c2.displayChild2();

	A4 h;
	h.showA1();
	h.showA2();
	h.showA3();
	h.showA4();

	return 0;
}
