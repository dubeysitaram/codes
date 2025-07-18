// 09_copyconstructor.cpp

#include <iostream>
using namespace std;

class Student
{
  public:
    string name;
    int age;

    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Student s1("Sitaram", 21);
    Student s2 = s1; // Copy constructor called
    s1.display();
    s2.display();
    return 0;
}
// 📌 Here, C++ compiler provides a default copy constructor, which performs a shallow copy.

