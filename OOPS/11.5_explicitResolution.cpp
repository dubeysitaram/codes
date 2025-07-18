/*

✅ What is Explicit Resolution in C++?
Explicit resolution means manually specifying the path through which you want
to access a member function or variable when there's ambiguity due to multiple inheritance.

🔍 Why is it needed?
In the diamond problem,
a derived class may inherit the same base class multiple times indirectly, causing ambiguity.

C++ compiler doesn't know which path to choose, so you must explicitly tell it.

*/

class Person {
public:
	void introduce() {
		cout << "I am a person.\n";
	}
};

class Teacher : public Person {};
class Researcher : public Person {};
class Professor : public Teacher, public Researcher {};

int main() {
	Professor p;
	// p.introduce(); ❌ Ambiguous

	// ✅ Explicit resolution
	p.Teacher::introduce();
	p.Researcher::introduce();
}
