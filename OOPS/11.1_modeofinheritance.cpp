#include <iostream>
using namespace std;

class Base {
private:
    int privateVar = 1;
    void privateMethod() {
        cout << "Base::privateMethod()\n";
    }

protected:
    int protectedVar = 2;
    void protectedMethod() {
        cout << "Base::protectedMethod()\n";
    }

public:
    int publicVar = 3;
    void publicMethod() {
        cout << "Base::publicMethod()\n";
    }

    void showBase() {
        cout << "THIS IS BASE CLASS" << endl;
        cout << "Accessing privateVar: " << privateVar << endl;
        privateMethod();
        cout << "Accessing protectedVar: " << protectedVar << endl;
        protectedMethod();
        cout << "Accessing publicVar: " << publicVar << endl;
        publicMethod();
    }
};

// 1. Public Inheritance
class PublicDerived : public Base {
public:
    void show() {
        // cout << privateVar;        ❌ Not accessible
        // privateMethod();          ❌ Not accessible

        cout << "PublicDerived: protectedVar = " << protectedVar << endl;  // ✅
        protectedMethod();                                                 // ✅

        cout << "PublicDerived: publicVar = " << publicVar << endl;        // ✅
        publicMethod();                                                    // ✅
    }
};

// 2. Protected Inheritance
class ProtectedDerived : protected Base {
public:
    void show() {
        // cout << privateVar;        ❌ Not accessible
        // privateMethod();          ❌ Not accessible

        cout << "ProtectedDerived: protectedVar = " << protectedVar << endl;  // ✅
        protectedMethod();                                                    // ✅

        cout << "ProtectedDerived: publicVar = " << publicVar << endl;        // ✅
        publicMethod();                                                       // ✅
    }
};

// 3. Private Inheritance
class PrivateDerived : private Base {
public:
    void show() {
        // cout << privateVar;        ❌ Not accessible
        // privateMethod();          ❌ Not accessible

        cout << "PrivateDerived: protectedVar = " << protectedVar << endl;  // ✅
        protectedMethod();                                                  // ✅

        cout << "PrivateDerived: publicVar = " << publicVar << endl;        // ✅
        publicMethod();                                                     // ✅
    }
};

int main() {
    Base b;
    b.showBase();              // ✅ Can access all within its own class
    cout << endl;

    PublicDerived p;
    p.show();                  // ✅ Can access public & protected
    cout << "Accessing PublicDerived publicVar: " << p.publicVar << endl; // ✅
    p.publicMethod();          // ✅
    // p.protectedMethod();    ❌
    cout << endl;

    ProtectedDerived q;
    q.show();                  // ✅ Can access inside class
    // q.publicMethod();       ❌ Not accessible outside (became protected)
    // cout << q.publicVar;    ❌
    cout << endl;

    PrivateDerived r;
    r.show();                  // ✅ Can access inside class
    // r.publicMethod();       ❌ Not accessible outside (became private)
    // cout << r.publicVar;    ❌
    cout << endl;

    return 0;
}
