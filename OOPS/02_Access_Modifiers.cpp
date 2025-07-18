#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

class Student
{
  private:
    int numberofgf;
  public:
    int id;
    int age;
    string name;
    int nos;
    bool flag;

    void Study()
    {
        cout << "I am studying " << "\n";
    }
    void Sleep()
    {
        cout << "I am Sleeping " << "\n";
    }
    void Bunk()
    {
        cout << "I am Bunking " << "\n";
    }
  private:
    void chatofgf()
    {
        cout << "hi i am chatting" << endl;
    }
};


void solve()
{
    Student s1;
    s1.Study();
    s1.Bunk();
    s1.chatofgf();
    // s1.chatofgf();// cannot access it
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}