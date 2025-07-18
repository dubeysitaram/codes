#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
const int N = 1e5 + 10;
// --------------------------------------------------------------------LCA IN O(N)---------------------------------------------------
vector<int> tree[N];
int parent[N];

void dfs(int vertex, int par) {
	parent[vertex] = par;
	for (auto child : tree[vertex]) {
		if (child == par) continue;
		dfs(child, vertex);
	}
}

vector<int> path(int v) {
	vector<int> ans;
	while (v != -1) {
		ans.push_back(v);
		v = parent[v];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void solve() {
	int n;
	cin >> n;

	// clear previous data
	for (int i = 0; i <= n; ++i) {
		tree[i].clear();
		parent[i] = -1;
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(0, -1);

	int node1, node2;
	cin >> node1 >> node2;

	vector<int> path1 = path(node1);
	vector<int> path2 = path(node2);

	int m = min(path1.size(), path2.size());
	int lca = -1;
	for (int i = 0; i < m; ++i) {
		if (path1[i] == path2[i]) {
			lca = path1[i];
		} else break;
	}

	cout << "LCA: " << lca << "\n";
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
