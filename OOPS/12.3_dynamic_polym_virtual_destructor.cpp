#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
	// To enable dynamic polymorphism, this should be virtual
	virtual void makesound() {
		cout << "animal make sound" << endl;
	}

	// Destructor should also be virtual to ensure proper cleanup of derived class objects
	virtual ~Animal() {
		cout << "I am Animal dtor" << endl;
	}
};

class Dog : public Animal {
public:
	void makesound() override {
		cout << "dog makes sound" << endl;
	}
	~Dog() override {
		cout << "I am Dog dtor" << endl;
	}
};

class Cat : public Animal {
public:
	void makesound() override {
		cout << "cat makes sound" << endl;
	}
	~Cat() override {
		cout << "I am Cat dtor" << endl;
	}
};

void sound(Animal *animal) {
	animal->makesound();
}

int main() {
	Animal *animal = new Dog();
	sound(animal);  // Output: dog makes sound (if makesound is declared virtual)

	animal = new Cat();
	sound(animal);  // Output: cat makes sound (if makesound is declared virtual)

	// Since we are using the new keyword, we have to delete the heap memory allocated
	// But when we write the delete animal command, it will
	// only call the destructor of the base class, not of the derived class whose memory was allocated
	// This is because we have not made the destructor virtual
	// So even though makesound is decided at runtime due to virtual,
	// destructor is not virtual by default and is resolved at compile time
	// This will lead to only calling the destructor of the base class
	// and this is not good because what if we dynamically allocate some heap memory inside the derived
	// class—that will lead to memory leakage
	// Hence, add the keyword `virtual` in front of the destructor of the base class also,
	// so that destruction of derived class objects happens properly via base class pointers

	delete animal;  // Important: Will only call derived destructor if base class destructor is virtual
}

