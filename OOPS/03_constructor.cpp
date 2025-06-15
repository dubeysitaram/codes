#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

class Student {
private:
	int numberofgf;
public:
	int id;
	int age;
	string name;
	int nos;
	bool flag;

	// Default constructor
	Student() {
		cout << "I am Defaultconstructor" << endl;
	}

	// Parameterized constructor
	Student(int _id, int _age , string _name, int _nos, bool _flag, int _numofgf) {
		id = _id;
		age = _age;
		name = _name;
		nos = _nos;
		flag = _flag;
		numberofgf = _numofgf;
	}

	void Study() { cout << "I am studying\n"; }
	void Sleep() { cout << "I am Sleeping\n"; }
	void Bunk()  { cout << "I am Bunking\n"; }

private:
	void chatofgf() {
		cout << "hi i am chatting" << endl;
	}
};

void solve() {
	Student s1; // Default constructor will be called
	Student s2(1, 12, "sitaram", 5, 0, 4);
	cout << s2.age << endl;
}

int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
