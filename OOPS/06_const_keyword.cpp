#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;




void solve() {
// const int x = 5 // x is a constant 
// initialization can be done 
// but we cant reassign the value 
// x=10; will give erorr
// cout<<x<<endl;
// const int n = 5;
// // n--;   // this is also not possible because the n is the const variable 
// cout<<n<<endl;

int *a  = new int;
*a = 2;
cout<<*a<<endl;
int b = 5;
a = &b;
cout<<*a<<endl;

}


int main() {
ios_base::sync_with_stdio(false),cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}