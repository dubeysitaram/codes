/*

✅ What is Virtual Inheritance?
Virtual inheritance is a C++ technique used in multiple inheritance
to ensure that only one copy of a base class is inherited,
even if it appears multiple times in the inheritance chain.

🔍 Why is it needed?
In diamond problem, a derived class may inherit the same base class multiple times through different paths, leading to:

❌ Multiple copies of the base class

❌ Ambiguity when accessing base members

✅ Virtual inheritance prevents this by telling the compiler to create only one shared copy of the base class.



*/



#include <iostream>
using namespace std;

class Person {
public:
    void introduce() {
        cout << "I am a person (virtual).\n";
    }
};

class Teacher : virtual public Person {
public:
    void teach() {
        cout << "I teach students.\n";
    }
};

class Researcher : virtual public Person {
public:
    void research() {
        cout << "I conduct research.\n";
    }
};

class Professor : public Teacher, public Researcher {
public:
    void guide() {
        cout << "I guide students.\n";
    }
};

int main() {
    Professor p;
    p.introduce();   // ✅ No ambiguity
    p.teach();
    p.research();
    p.guide();

    return 0;
}
