/*
Polymorphism means one function behaving differently based on the object.
 It allows the same function name to perform different tasks. In C++, it is of two types — 
 compile-time using function overloading and run-time using virtual functions.


 📚 Types of Polymorphism:

1. Compile-time Polymorphism (Static Binding)
Achieved using:

a) Function Overloading

b) Operator Overloading

2. Run-time Polymorphism (Dynamic Binding)

Achieved using:

Function Overriding + Virtual Functions



*/

/* ✅ 1. Compile-time Polymorphism

🔹 Function Overloading Example:
*/
#include<iostream>
using namespace std;

class Print {
public:
    void show(int a) {
        cout << "Integer: " << a << endl;
    }
    void show(double a) {
        cout << "Double: " << a << endl;
    }
    void show(string a) {
        cout << "String: " << a << endl;
    }
};

int main() {
    Print obj;
    obj.show(5);         // Integer
    obj.show(3.14);      // Double
    obj.show("Hello");   // String
}

// ✅ 2. Operator Overloading Example: it is n

class Complex {
public:
    int real, imag;
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    void operator + (const Complex& other) {
        this->real = this->real + other.real;
        this->imag = this->imag + other.imag;
    }

    void operator - (const Complex& other) {
        this->real = this->real - other.real;
        this->imag = this->imag - other.imag;
    }

    void operator * (const Complex& other) {
        int r = this->real * other.real - this->imag * other.imag;
        int i = this->real * other.imag + this->imag * other.real;
        this->real = r;
        this->imag = i;
    }

    void operator == (const Complex& other) {
        if (this->real == other.real && this->imag == other.imag)
            cout << "Both complex numbers are equal." << endl;
        else
            cout << "Complex numbers are not equal." << endl;
    }

    void operator++() {
        ++real;
        ++imag;
    }

    void operator--() {
        --real;
        --imag;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex a(2, 3), b(1, 4);

    cout << "Original A: "; a.display();
    cout << "Original B: "; b.display();

    a + b;
    cout << "\nAfter A + B: "; a.display();

    a - b;
    cout << "After A - B: "; a.display();

    a * b;
    cout << "After A * B: "; a.display();

    Complex c(2, 3);
    cout << "\nCompare A and C: ";
    a == c;

    ++a;
    cout << "After ++A: "; a.display();

    --a;
    cout << "After --A: "; a.display();

    return 0;
}