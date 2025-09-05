/*
 **
    WE REQURE HIGH COHESION AND LOW COUPLING AS COHESION IS DONE IN A SINGLE CLASS AND COUPLING IS DONE B/W THE CLASSES
    SO THE INTERDEPENDENCCY OF THE CLASSES ON EACH OTHE SHOULD BE AS MINIMAL AS POSSIBLE


11. What is cohesion in OOP?

Cohesion in OOP refers to how closely the methods and data within a single class are related to one another.
A highly cohesive class is focused on a specific task or responsibility, making it easier to maintain, understand, and ensure reliability.

High cohesion is a desired attribute because it means that methods and properties within a class work together in a unified manner.
In contrast, low cohesion indicates that a class has multiple, often unrelated responsibilities, making it harder to understand and maintain.

Levels of Cohesion
Coincidental: Methods and properties within the class have no meaningful relationship.
Logical: Methods are grouped based on some logic but lack a clear theme.
Temporal: Methods are related by when they are executed, e.g., initialization methods.
Procedural: Methods are executed in a specific sequence.
Communicational: Methods work on the same set of data.
Sequential: The output of one method serves as the input for another.
Functional: All methods in the class contribute to a single well-defined task.
Of these, functional cohesion is the most desirable, as it closely aligns with the Single Responsibility Principle.

*/

// ✅ Example of Low Cohesion (Bad Design) ek feature ka dusre se koi interaction hi nhi hai
#include <bits/stdc++.h>
using namespace std;

class Utility
{
  public:
    string readFile(const string &fileName)
    {
        // dummy file read
        return "file content";
    }

    void writeToDatabase(const string &data)
    {
        // dummy database write
        cout << "Writing to DB: " << data << endl;
    }

    void clearCache()
    {
        cout << "Cache cleared\n";
    }

    vector<string> parseContent(const string &content)
    {
        return { "parsed1", "parsed2" };
    }
};

//✅ High Cohesion (Good Design with SRP) Each class has a single responsibility — promoting high cohesion.

#include <bits/stdc++.h>
using namespace std;

class FileHandler
{
  public:
    string readFile(const string &fileName)
    {
        return "file content";
    }
};

class Parser
{
  public:
    vector<string> parse(const string &content)
    {
        return { "parsed1", "parsed2" };
    }
};

class DatabaseWriter
{
  public:
    void write(const string &data)
    {
        cout << "Writing to DB: " << data << endl;
    }
};

class CacheManager
{
  public:
    void clear()
    {
        cout << "Cache cleared\n";
    }
};

