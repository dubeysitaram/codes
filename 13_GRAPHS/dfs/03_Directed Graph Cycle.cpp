// Directed Graph Cycle.cpp
/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.
*/

class Solution {
public:
	bool dfs(int node, vector<int>g[], vector<int>&vis, vector<int>&pathvis) {
		pathvis[node] = 1;
		vis[node] = 1;
		for (auto it : g[node]) {
			if (!vis[it]) {
				if (dfs(it, g, vis, pathvis))return true;
			} else if (pathvis[it]) {
				return true;
			}
		}
		pathvis[node] = 0;
		return false;
	}
	bool isCyclic(int V, vector<vector<int>> &edges) {
		// code here
		vector<int>g[V];
		for (auto it : edges) {
			int u = it[0], v = it[1];
			g[u].push_back(v);
		}
		vector<int>vis(V, 0), pathvis(V, 0);
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfs(i, g, vis, pathvis))return true;
			}
		}
		return false;

	}
};