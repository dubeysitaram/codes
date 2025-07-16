/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is
only one way to travel between two different cities (this network form a tree).
Last year, The ministry of transport decided to orient the roads in one
direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents
a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people
want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the
city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
*/

// ek baar ke dfs mai hi saare nodes vis marked ho jayeenge due to addition of reversed edges hence its working


class Solution {
public:
	int ct = 0;
	void dfs(int parent, vector<vector<pair<int, int>>>& graph,
	         vector<int>& vis) {
		vis[parent] = 1;
		for (auto it : graph[parent]) {
			if (!vis[it.first]) {
				ct += it.second; // increment if edge is away from 0
				dfs(it.first, graph, vis);
			}
		}
	}

	int minReorder(int n, vector<vector<int>>& connections) {
		vector<vector<pair<int, int>>> graph(n);
		vector<int> vis(n, 0);
		for (auto& conn : connections) {
			graph[conn[0]].push_back({conn[1], 1}); // original edge
			graph[conn[1]].push_back({conn[0], 0}); // reverse edge
		}
		dfs(0, graph, vis);
		return ct;
	}
};