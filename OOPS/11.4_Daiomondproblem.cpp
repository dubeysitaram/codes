/*
The Diamond Problem occurs in multiple inheritance when a class inherits from two classes that
both inherit from a common base class.
This causes ambiguity because the derived class ends up with multiple copies of the base class.

✅ Explain with Example:

For example, if Professor inherits from both Teacher and Researcher,
and both of them inherit from Person, then Professor gets two copies of Person.

Now, if Professor tries to call a method like introduce() from Person,
the compiler doesn’t know which path to follow — via Teacher or Researcher.
This ambiguity is called the Diamond Problem.

       Person
       /    \
  Teacher  Researcher
       \    /
     Professor

How to Solve It:
The Diamond Problem is solved using virtual inheritance.
When we write class Teacher : virtual public Person,
it tells the compiler to share a single copy of Person for all derived classes.

✅ Bonus Tip (short version):
The Diamond Problem is an ambiguity in multiple inheritance
when a class indirectly inherits from the same base class via two paths.
It is best solved using virtual inheritance

*/


#include <iostream>
using namespace std;

class Person {
public:
	void introduce() {
		cout << "I am a person.\n";
	}
};

class Teacher : public Person {
public:
	void teach() {
		cout << "I teach students.\n";
	}
};

class Researcher : public Person {
public:
	void research() {
		cout << "I conduct research.\n";
	}
};

// Diamond Problem: Professor inherits from both Teacher and Researcher
class Professor : public Teacher, public Researcher {
public:
	void guide() {
		cout << "I guide students.\n";
	}
};

int main() {
	Professor p;
	// p.introduce(); ❌ Ambiguous: compiler doesn't know whether to use Teacher::Person or Researcher::Person
	p.Teacher::introduce();     // ✅ Explicit resolution
	p.Researcher::introduce();  // ✅ Explicit resolution

	p.teach();
	p.research();
	p.guide();

	return 0;
}
