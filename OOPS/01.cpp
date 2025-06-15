#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

class Student {
	int id;
	// int age;    //4 bytes
	string name;
	// int nos;    //4 bytes
	// bool flag;  //4 bytes
	// void Study() {
	// 	cout << "I am studying " << "\n";

	// }
	// void Sleep() {
	// 	cout << "I am Sleeping " << "\n";

	// }
	// void Bunk() {
	// 	cout << "I am Bunking " << "\n";

	// }
};
class Student2 {
	double a, b;
	char c;

};
class Student3 {

	bool d;
};
class Student4 {
	string name;
};
class Student5 {
	int id;
	int age;    //4 bytes
	string name;
	int nos;    //4 bytes
	bool flag;
};
int age(int x) {
	return x;
}


void solve() {
	int a;
	cout << sizeof(Student2) << endl;
	cout << sizeof(Student3) << endl;
	cout << sizeof(Student4) << endl;
	cout << sizeof(Student5) << endl;
	// cout << sizeof(Student) << endl;

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