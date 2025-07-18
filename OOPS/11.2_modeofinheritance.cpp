
//Both ✅ data members and ✅ member functions (methods) can be public,
//protected, or private in C++.


#include <iostream>
using namespace std;

class MyClass {
private:
    int secret = 10;               // private data member
    void privateMethod() {         // private method
        cout << "Private method\n";
    }

protected:
    int semiSecret = 20;           // protected data member
    void protectedMethod() {       // protected method
        cout << "Protected method\n";
    }

public:
    int open = 30;                 // public data member
    void publicMethod() {          // public method
        cout << "Public method\n";
        privateMethod();           // ✅ accessible within class
    }
};

// | Member Type | Accessible in Class | Accessible in Derived Class | Accessible from Object |
// | ------------|---------------------| --------------------------- | ---------------------- |
// | `private`   | ✅ Yes               | ❌ No                        | ❌ No                |
// | `protected` | ✅ Yes               | ✅ Yes                       | ❌ No                |
// | `public`    | ✅ Yes               | ✅ Yes                       | ✅ Yes               |
