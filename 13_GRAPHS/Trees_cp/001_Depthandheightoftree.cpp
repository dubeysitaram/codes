#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

const int N = 1e5 + 10;
int depth[N];
int height[N];

void dfs(int node, int parent, vector<int>edges[]) {
	
	for (auto child : edges[node]) {
		if (child == parent) continue;

		depth[child] = depth[node] + 1;

		dfs(child, node, edges);

		height[node] = max(height[node], height[child] + 1);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int>g[n];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0, -1, g);

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