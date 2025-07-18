/*
friend is a keyword in C++ that is used to share the information of a class that was previously hidden.

For example, the private members of a class are hidden from every other class and cannot be modified except through getters or setters.

Similarly, the protected members are hidden from all classes other than its children classes."

*/

#include<bits/stdc++.h>
using namespace std;

class A
{
  private:
    int x;
  public:
    A(int _x): x(_x)
    {
        //intainiting list
    }
    int getX() const
    {
        return x;
    }
    void set(int y)
    {
        this->x = y;
    }
    void printX() const // ye prefer karo instead of friend keyword
    {
        cout << x << endl;
    }
    friend class B; // FRIEND CLASS
    friend int value(const A &);// // FRIEND FUNCTION
};
// class B prints the data members of the class A

class B
{
  public:
    int getx(const A &p)
    {
        cout << p.x << endl;
        // pehle nhi dekh paa rha tha  x ko ,so b ko friend class banate hi erorr gone
        // insted of doing above this do
        p.printX();
        return p.getX();
    }
};

int value(const A &p)
{
    cout << p.x << endl;
    // pehle nhi dekh paa rha tha  x ko ,so value ko friend class banate hi erorr gone
    return p.getX();
}
int main()
{
    A *a = new A(20);
    cout << a->getX() << endl;
    B *b;
    cout << b->getx(*a) << endl;
    a->printX();
}
