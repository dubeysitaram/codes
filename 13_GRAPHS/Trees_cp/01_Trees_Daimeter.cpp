#include<bits/stdc++.h>
using namespace std;

void dfs(int source, int parent, int curlevel, vector<int>&level, vector<vector<int>>&edges) {
	for (auto child : edges[source]) {
		if (child != parent) {
			level[child] = curlevel + 1;
			dfs(child, source, curlevel + 1, level, edges);
		}
	}

}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> edges(n);

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	vector<int>levelX(n, 0);
	dfs(0, -1, 0, levelX, edges);
	int node = max_element(levelX.begin(), levelX.end()) - levelX.begin();
	fill(levelX.begin(), levelX.end(), 0);
	dfs(node, -1, 0, levelX, edges);
	int daimater = *max_element(levelX.begin(), levelX.end());
	cout << daimater << "\n";
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