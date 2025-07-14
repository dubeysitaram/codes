/*
Given a directed graph and a vertex_source node and destination node,
we need to find how many edges we need to reverse in order to make at least 1 path
from the vertex_source node to the destination node.

*/
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
					dq.push_front(v); // aage daalenge
				else
					dq.push_back(v);  // piche daalenege
			}
		}
	}

	return level;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (x == y) continue; // skip self-loop

		graph[x].push_back({y, 0}); // original direction
		graph[y].push_back({x, 1}); // reversed with cost inserted by us
	}

	int nodetoreach;
	cin >> nodetoreach;

	vector<int> dist = zeroOneBFS(n, graph, 0);

	cout << (dist[nodetoreach] == INF ? -1 : dist[nodetoreach]) << endl;

	return 0;
}
