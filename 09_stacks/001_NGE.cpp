#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;


vector<int>NGE(vector<int>&nums) {
	stack<int>st;
	vector<int>ans(n, -1);
	for (int i = 0; i < n; i++) {
		while (!st.empty() && nums[st.top()] < nums[i]) {
			ans[st.top] = i;
			st.pop();
		}
		st.push(i);
	}

}

void solve() {


}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}


for (int i = 0; i < n; i++) {
	while (!st.empty() && arr[i] > arr[st.top()]) {
		ans[st.top()] = i;
		st.pop();
	}
	st.push(i);

}
for (int i = n - 1; i >= 0; i++) {
	while (!st.empty() &&  )
	}