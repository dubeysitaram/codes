#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> zeroOneBFS(int n, vector<vector<pair<int, int>>>& adj, int src) {
	deque<int> dq;
	vector<int> level(n, INF);

	level[src] = 0;
	dq.push_front(src);

	while (!dq.empty()) {
		int u = dq.front();
		dq.pop_front();

		for (auto [v, wt] : adj[u]) {
			if (level[u] + wt < level[v]) {
				level[v] = level[u] + wt;
				if (wt == 0)
					dq.push_front(v);
				else
					dq.push_back(v);
			}
		}
	}

	return level;
}

int main() {
	int n = 5; // number of nodes
	vector<vector<pair<int, int>>> adj(n);

	// add edges: (u, v, weight)
	adj[0].push_back({1, 0});
	adj[0].push_back({2, 1});
	adj[1].push_back({2, 0});
	adj[1].push_back({3, 1});
	adj[2].push_back({3, 0});
	adj[3].push_back({4, 1});

	vector<int> dist = zeroOneBFS(n, adj, 0);

	for (int i = 0; i < n; ++i)
		cout << "Distance to " << i << ": " << dist[i] << endl;
}
