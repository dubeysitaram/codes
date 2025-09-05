/*
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights.
Find the shortest weight path between the vertex 1 and the vertex n,
if there exists a path, and return a list of integers whose first element is the weight of the path,
and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.
Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights
along the nodes on that path, if equal it will output the weight of the path, else -2.
In case the list contains only a single element (-1) it will simply output -1.
*/

class Solution {
public:
	vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
		vector<pair<int, int>> g[n + 1];
		for (int i = 0; i < m; i++) {
			g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
			g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
		}

		vector<int> parent(n + 1);
		for (int i = 0; i <= n; i++) parent[i] = i;

		vector<int> dis(n + 1, INT_MAX);
		dis[1] = 0;

		multiset<pair<int, int>> ms;
		ms.insert({0, 1});

		while (!ms.empty()) {
			auto it = *ms.begin();
			int d = it.first;
			int u = it.second;
			ms.erase(ms.begin());

			if (dis[u] < d) continue;

			for (auto it : g[u]) {
				int v = it.first;
				int w  = it.second;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					ms.insert({dis[v], v});
					parent[v] = u;
				}
			}
		}

		if (dis[n] == INT_MAX || parent[n] == n) return { -1}; // no path

		vector<int> ans;
		int i = n;
		while (parent[i] != i) {
			ans.push_back(i);
			i = parent[i];
		}
		ans.push_back(1);
		ans.push_back(dis[n]);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
