#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

class Student {

public:
	string name;
	int age;
	// Default constructor
	Student() {
		cout << "Default Constructor Called" << endl;
	}
	// paramaterized constructor
	Student(string name , int age) {
		cout << "student paramaterized Constructor Called" << endl;
		this->name = name;
		this->age = age;
	}
	// copy constructor
	Student(const Student& srcobj) {
		cout << "student copy Constructor Called" << endl;
		this->name = srcobj.name;
		this->age = srcobj.age;
	}

	void display() {
		cout << "name-> " << name << ", age-> " << age << endl;
	}

};


void solve() {

	Student s1("sitaram", 23);
	s1.display();
	Student s2 = s1;// copy constructor will be called
	Student s3; // no copy constructor will be called
	s3 = s1;
	// constructor should be called at the time of the object creation only
	// but here when the object is created the copy constructor is not called
	// the copy constructor should only be called at the timeof the object intaintiation only
	/*

	so we have two ways to do so
	1)-->  Student s2 = s1;
	2)-->  Student s2(s1);
	both do same work
	*/


}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}