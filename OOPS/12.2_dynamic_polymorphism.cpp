#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
	// To enable dynamic polymorphism, this should be virtual
	void makesound() {
		cout << "animal make sound" << endl;
	}
};

class Dog : public Animal {
public:
	void makesound() {
		cout << "dog makes sound" << endl;
	}
};

class Cat : public Animal {
public:
	void makesound() {
		cout << "cat makes sound" << endl;
	}
};

void sound(Animal *animal) {
	animal->makesound();
}

int main() {
	// These both objects will call the base class makesound() function
	// because makesound() is not marked as virtual in the base class.
	// So, the function binding happens at compile time (static binding).
	// To achieve dynamic polymorphism, we must mark the base class method as virtual.
	// Then, the call to makesound() will be resolved at runtime (dynamic dispatch).

	Animal *animal = new Dog();
	sound(animal);  // Output: animal make sound (not Dog’s version)

	animal = new Cat();
	sound(animal);  // Output: animal make sound (not Cat’s version)
}
//  we want this so that our task to write the code decreases

// -------------------------------- CODE AFTER USING THE VIRTUAL KEYWORD---------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
	// Marking this function as virtual enables dynamic binding.
	// Now, the version of makesound() that gets called depends on the actual object type at runtime.
	virtual void makesound() {
		cout << "animal makes sound" << endl;
	}
};
// we write the override keyword only to increase the readability
class Dog : public Animal {
public:
	// Overrides Animal::makesound()
	void makesound() override {
		cout << "dog makes sound" << endl;
	}

};

class Cat : public Animal {
public:
	// Overrides Animal::makesound()
	void makesound() override {
		cout << "cat makes sound" << endl;
	}
};

// This function uses a base class pointer.
// With 'virtual', it will now call the correct overridden function based on actual object type.
void sound(Animal *animal) {
	animal->makesound();
}

int main() {
	// Pointer to Dog object — will now call Dog's makesound() due to dynamic dispatch.
	Animal *animal = new Dog();
	sound(animal);  // Output: "dog makes sound"

	// Pointer to Cat object — will now call Cat's makesound()
	animal = new Cat();
	sound(animal);  // Output: "cat makes sound"

	/*
		Output:
		dog makes sound
		cat makes sound

		Thanks to the virtual keyword, the correct derived class function
		is now called based on the object type at runtime.
	*/
}

//--------------------------------STOPPING THE MEMORY LEAKAGE--------------------------------------


