#include <iostream>
using namespace std;

class Sample {
private:
    const int id;           // const integer
    int value;              // regular int
    int* ptr;               // pointer
    string name;            // string object
    int& ref;               // reference to int

public:
    // Constructor using initialization list
    Sample(int _id, int _value, string _name, int& externalRef) : id(_id), value(_value), ptr(new int(_value * 2)), name(_name), ref(externalRef)
    {
        cout << "Constructor initialized all members.\n";
    }

    void show() {
        cout << "ID (const): " << id << endl;
        cout << "Value: " << value << endl;
        cout << "Pointer points to: " << *ptr << endl;
        cout << "Name: " << name << endl;
        cout << "Reference refers to: " << ref << endl;
    }

    ~Sample() {
        delete ptr; // free heap memory
    }
};

int main() {
    int external = 99;
    Sample obj(1, 50, "Sitaram", external);
    obj.show();
    return 0;
}
