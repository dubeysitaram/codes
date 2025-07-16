#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;


vector<int>g[N];

void dfs(int vertex, int par) {
	/** take action on vertex after entering the vertex */

	for (int child : g[vertex]) {
		if (child == par)continue;
		/** take action on child before entering the child NODE*/
		dfs(child, vertex);
		/*
		* take action on child after exiting the child NODE* (precomputation mai yahi wala positionn use hota hai )
		* we use it to do calculations like sum,minimum,evenoddcount from down to up
		*/
	}
	/** take action on vertex before exiting the vertex */
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