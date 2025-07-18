/*
🔥 1. Can static functions access non - static members ?

Trick : Many assume they can if an object is used.

✅ Answer :
No. Static functions cannot access non - static data members directly because they don’t have a this pointer.


static void func() {
    cout << name; // ❌ Error if 'name' is non-static
}

// ----------------------------------------------------------------------------------------------------------------

🔥 2. Is memory allocated for static variables every time an object is created ?
Trick : Many think it gets recreated for each object.

    ✅ Answer :
    No. Static variables are allocated once in memory, outside any object. All objects share it.


// --------------------------------------------------------------------------------------------------------------
    🔥 3. Can we initialize a static member inside the class ?
        ✅ Answer :
        No, except for const static integral types (like const static int x = 10;).

                For normal static members :

                class A {
                    static int x;       // Declaration
                };
int A::x = 5;           // ✅ Defined outside
// ------------------------------------------------------------------------------------------------------------------


🔥 4. Can we have a static constructor in C++ ?
✅ Answer :

No. C++ does not support static constructors like C# or Java.

// ----------------------------------------------------------------------------------------------------------

🔥 5. What is the lifetime of a static variable inside a function ?
✅ Answer :
Its lifetime is until the end of the program, not just the function scope. Value is retained across calls.

/*--------------------------------------------------------------------------------------------------------------------
🔥 6. Can static functions be virtual or overridden?
✅ Answer:
No. Static functions cannot be virtual because they are not tied to an object and don’t use vtables.

/*-----------------------------------------------------------------------------------------------------------
🔥 7. Can you access a static function using an object?
✅ Answer:
Yes, but it's not recommended. You should call it using the class name.


obj.staticFunc();    // ✅ Works, but bad style
ClassName::staticFunc(); // ✅ Preferred

/*

---------------------------------------------------------------------------------------------
🔥 8. Can a static function use this pointer?
✅ Answer:
No. Static functions don’t belong to any object, so this is not available.


🔥 9. Where are static members stored in memory?
✅ Answer:
Static members are stored in data segment (global/static memory), not on stack or heap.

🔥 10. Can a static variable be private and still be used?
✅ Answer:
Yes. You can make a static variable private and provide public static functions(getter and setters) to access it.

class Counter {
private:
    static int count;
public:
    static int getCount() { return count; }
};
*/