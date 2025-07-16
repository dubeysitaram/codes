// 04_Tree_Distances_II.cpp
/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the sum of the distances from the node to all other nodes.
Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print n integers: for each node 1,2,\ldots,n, the sum of the distances.
Constraints

1 <= n<=10^5
1 <= a,b <= n

Example
Input:
5
1 2
1 3
3 4
3 5

Output:
6 9 5 8 8
*/
#include<bits/stdc++.h>
using namespace std;
void dfs1(ll source, ll parent, ll curlevel, vector<ll>&level, vector<vector<ll>>&edges, vector<ll>&subtreesizeofeachnode) {

	for (auto child : edges[source]) {
		if (child != parent) {
			level[child] = curlevel + 1;
			dfs1(child, source, curlevel + 1, level, edges, subtreesizeofeachnode);
			subtreesizeofeachnode[source] += subtreesizeofeachnode[child];
		}
	}

}

void dfs2(ll source, ll parent, vector<ll>&subtreesizeofeachnode, vector<vector<ll>>&edges, vector<ll>&ans) {
	ll n  = edges.size();
	for (auto child : edges[source]) {

		if (child != parent) {
			ans[child] = ans[source] + (n - subtreesizeofeachnode[child]) * 1ll + (-1ll * subtreesizeofeachnode[child]);
			dfs2(child, source, subtreesizeofeachnode, edges, ans);
		}
	}


}


void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> edges(n);

	for (ll i = 0; i < n - 1; ++i) {
		ll x, y;
		cin >> x >> y;
		x--; y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	vector<ll>levelX(n, 0);
	vector<ll>subtreesizeofeachnode(n, 1);
	dfs1(0, -1, 0, levelX, edges, subtreesizeofeachnode);
	vector<ll>ans(n, 0);
	ans[0] = accumulate(levelX.begin(), levelX.end(), 0 * 1ll);
	dfs2(0, -1, subtreesizeofeachnode, edges, ans);
	for (auto it : ans) {
		cout << it << " ";
	}



}


int main() {

	ios_base::sync_with_stdio(false),
	         cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}