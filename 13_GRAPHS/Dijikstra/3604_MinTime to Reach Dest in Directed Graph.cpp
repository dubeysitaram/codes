/*
3604. Minimum Time to Reach Destination in Directed Graph
You are given an integer n and a directed graph with n nodes labeled from 0 to n - 1.
This is represented by a 2D array edges, where edges[i] = [ui, vi, starti, endi]
indicates an edge from node ui to vi that can only be used at any integer time t such that starti <= t <= endi.

You start at node 0 at time 0.

In one unit of time, you can either:

Wait at your current node without moving, or
Travel along an outgoing edge from your current node if the current time t satisfies starti <= t <= endi.
Return the minimum time required to reach node n - 1. If it is impossible, return -1
*/

class Solution {
public:
	int minTime(const int n, vector<vector<int>>& edges) {
		vector<vector<vector<int>>> g(n);
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0], v = edges[i][1], s = edges[i][2], e = edges[i][3];
			g[u].push_back({v, s, e});
		}

		vector<int> dis(n, INT_MAX);
		multiset<pair<int, int>> ms;
		ms.insert({0, 0});
		dis[0] = 0;

		while (!ms.empty()) {
			auto [d, v] = *ms.begin();
			ms.erase(ms.begin());
			if (d > dis[v]) continue;

			for (auto &it : g[v]) {
				int to = it[0], st = it[1], en = it[2];
				if (d > en) continue;
				if (dis[to] > max(st, d)) {
					dis[to] = 1 + max(st, d);
					ms.insert({dis[to], to});
				}
			}
		}

		return (dis[n - 1] == INT_MAX) ? -1 : dis[n - 1];
	}
};
