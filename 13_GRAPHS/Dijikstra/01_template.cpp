#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &graph) {
	vector<int> dist(n, INF), vis(n, 0);
	set<pair<int, int>> st;
	dist[src] = 0;
	st.insert({0, src});

	while (!st.empty()) {
		auto it = st.begin();
		int node = it->second;
		st.erase(it);

		if (vis[node]) continue;
		vis[node] = 1;

		for (auto [child, wt] : graph[node]) {
			if (dist[node] + wt < dist[child]) {
				dist[child] = dist[node] + wt;
				st.insert({dist[child], child});
			}
		}
	}
	return dist;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		// graph[v].push_back({u, w}); // if undirected
	}

	int src;
	cin >> src;

	vector<int> dist = dijkstra(src, n, graph);

	for (auto d : dist) {
		if (d == INF) cout << "INF ";
		else cout << d << " ";
	}
	cout << endl;
}
