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


#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int minOperations(vector<int> prices, int k, int d) {
    multiset<int> ms(prices.begin(), prices.end());
    int ops = 0;
    while (true) {
        auto it_min = ms.begin();
        auto it_max = prev(ms.end());
        int mn = *it_min;
        int mx = *it_max;
        if (mx - mn < d) 
            break;

        int p = min({k, mx - 1, (mx - mn) / 2});
        if (p < 1) {
            return -1;
        }
        ms.erase(it_min);
        ms.erase(it_max);
        ms.insert(mn + p);
        ms.insert(mx - p);
        ops++;
    }
    return ops;
}