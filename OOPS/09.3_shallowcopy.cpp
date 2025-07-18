#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

class Student
{

  public:
    string name;
    int age;
    // Default constructor
    Student()
    {
        cout << "Default Constructor Called" << endl;
    }
    // paramaterized constructor
    Student(string name, int age)
    {
        cout << "student paramaterized Constructor Called" << endl;
        this->name = name;
        this->age = age;
    }
    // copy constructor
    Student(const Student &srcobj)
    {
        cout << "student copy Constructor Called" << endl;
        this->name = srcobj.name;
        this->age = srcobj.age;
    }

    void display()
    {
        cout << "name-> " << name << ", age-> " << age << endl;
    }

};
class ABC
{
  public:
    int x;
    int *y;

    ABC(int _x, int _y): x(_x), y(new int(_y))
    {
    }

    void Print()
    {
        cout << "x" << " " << x << " " << "y" << " " << y << endl;
    }
    // when we called that ABC a(2,3)  a integer is assigned to a memory and a heap memory  is allocated to y variable
    // when we called the--->  ABC b(a) then
    // x 2 y 0x5c2a076f92c0
    // x 2 y 0x5c2a076f92c0
    // both a and b become dependent both a and b object are pointing at same location
    // changing the value of the y will change the value for both objects this happens because when we do b=a then c++
    //  adds the dumb copy constructor
    //Dumb constructor---> it does shallow copy pointer inside the a is directly coped in b which is a major security flaw

    ABC(const ABC &src) // shallow done default done by compiler
    {
        this->x = src.x;
        this->y = src.y;
    }
    ABC(const ABC
        &src)// src object 2 hai jiski copy baanni na ki uska address ye ek alias hai us obj ka jiski deep copy banni hai
    {
        this->x = src.x;
        this->y = new int(*(src).y); // nayi memory assign krdi
        /*

        important agr object ke members ko access karna hai to . operator ka use krenge
        //  and to access the pointer members we uses the -> operator
        | You have         | Use  |
        | ---------------- | ---- |
        | `object`         | `.`  |
        | `object pointer` | `->` |

        ✅ What's happening step-by-step:

        src is a reference to an existing object (e.g., ABC a(2, 3); ABC b(a);).

        src.y accesses the pointer y from the source object → this is an address (e.g., 0x7ffeabcd).

        *src.y dereferences that pointer → gives the value stored at that address (say, 3).

        new int(*src.y) allocates a new memory block and copies the value 3 into it.

        this->y = ... makes the new object's pointer point to this new memory. */
    }
};


int main()
{
    Student s1("sitaram", 23);
    s1.display();
    Student s2 = s1;// copy constructor will be called
    Student s3; // no copy constructor will be called
    s3 = s1;
    // constructor should be called at the time of the object creation only
    // but here when the object is created the copy constructor is not called
    // the copy constructor should only be called at the timeof the object intaintiation only
    /*

    so we have two ways to do so
    1)-->  Student s2 = s1;
    2)-->  Student s2(s1);
    both do same work
    */
    ABC a(2, 3);
    a.Print();
    ABC b(a);
    b.Print();
    *b.y = 20;
    // changing the value of the y will change the value for both objects this happens because when we do b=a then c++
    //  adds the dumb copy constructor
    a.Print();
    b.Print();
}




/*

so when we are declaring this Student* s = new Student();
and then doing the cout<<*s<<endl; these both * are diffrent one is Student*  and other * is of derefrencing
2)
Student* s = new Student();
agar hum  cout<<&s<<endl; karenge then it will print the stack address of the poinetr variable pointing to the location in heap memory

| Expression | Meaning                                               | What it prints        |
| ---------- | ----------------------------------------------------- | --------------------- |
| s      | Address of the `Student` object (i.e., heap address)  | ✔️ Object's memory    |
| *s      | Dereferenced object (access members with `s->`)       | ❌ Won’t print address |
| &s     | Address of the pointer variable `s` itself (in stack) | ⚠️ Pointer’s address  |


*/