/*
12. What is coupling in OOP?

Coupling in OOP describes the degree of interdependence between classes or modules. 
It determines how closely different modules or classes are linked to each other, impacting the system's flexibility, maintainability, and testability.

Loose coupling is generally preferred in software design.

Types of Coupling

Content Coupling: This is the strongest form of coupling where one module directly accesses or modifies another module's internal data.

Common Coupling: Multiple modules share access to common global data. Any change to this shared resource can affect all the modules that depend on it.

Control Coupling: One module controls the flow of another by passing it control information, such as using flags.

External Coupling: Classes or modules are linked by external factors, such as configuration files or data schemas.

Stamp (or Data) Coupling: Modules share data structures and use only parts of them, requiring knowledge about the structure of the data being passed.

Message Coupling: The lowest form of coupling where modules communicate only through standard interfaces, such as method calls or messages.

Relationship with SOLID Principles

Single Responsibility Principle (SRP): Adhering to SRP typically results in low coupling since classes have a singular focus, 
thereby minimizing dependencies.

Open-Closed Principle (OCP): Emphasizing extensibility without modification, 
OCP reduces the risk of tight coupling as extensions are typically made through interfaces or abstract classes.

Liskov Substitution Principle (LSP): When derived classes can replace their base classes without side effects, 
there's often a reduction in coupling, ensuring modules can operate independently of the specific derived class in use.

Interface Segregation Principle (ISP): By endorsing focused interfaces rather than "one-size-fits-all" ones, 
ISP naturally leads to decreased coupling as classes aren't forced to depend on methods they don't use.

Dependency Inversion Principle (DIP): By relying on abstractions rather than concrete implementations, 
DIP promotes low coupling, making systems more modular and adaptable.

 */

//  ✅ Loosely Coupled using Interface (Good Design)
#include<bits/stdc++.h>
using namespace std;
class IEngine
{
  public:
    virtual void start() = 0;
    virtual ~IEngine() = default;
};

class PetrolEngine : public IEngine
{
  public:
    void start() override
    {
        cout << "Petrol Engine started\n";
    }
};

class Car
{
    IEngine *engine;

  public:
    Car(IEngine *eng) : engine(eng) {}

    void startCar()
    {
        engine->start();
    }
};
// 🔴 Tightly Coupled (Bad Design)

class Engine
{
  public:
    void start()
    {
        cout << "Engine started\n";
    }
};

class Car
{
    Engine engine; // tightly coupled to specific Engine class

  public:
    void startCar()
    {
        engine.start();
    }
};
