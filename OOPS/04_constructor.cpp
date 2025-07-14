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
	string name,birthplace , college;;
	int nos;
	bool flag;

	// Default constructor removed so khokhla student nhi ban payegaa
	// Student() {
	// 	cout << "I am Defaultconstructor" << endl;
	// }

	// first Parameterized constructor with this pointer
	Student(int _id, int _age , string _name, int _nos, bool _flag, int _numofgf) {
		this->id = _id;
		this->age = _age;
		this->name = _name;
		this->nos = _nos; 
		this->flag = _flag;
		this->numberofgf = _numofgf;
	}

	// second Parameterized constructor 
	Student (string _name , string _birthplace , string _college){
      name = _name;
      birthplace = _birthplace;
      college =_college;
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
	Student s1;// Default constructor is not present "ERORR WILL BE THROWN SO WE HAVE TO COMMENT THIS "
	Student s2(1, 12, "sitaram", 5, 0, 4);// paramaterized constructor is called beacuse the parameters are passed
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

