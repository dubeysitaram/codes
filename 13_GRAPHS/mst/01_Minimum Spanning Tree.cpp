/*
Given a weighted, undirected, and connected graph with V vertices and E edges,
your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.
The graph is represented by an adjacency list, where each element adj[i] is a
vector containing vector of integers. Each vector represents an edge,
with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.
*/
class Solution {
public:
	static const int N = 1e6 + 10;
	int parent[N];
	int Size[N];

	void make(int i) {
		parent[i] = i;
		Size[i] = 1;
	}

	int find(int i) {
		if (parent[i] == i) return i;
		return parent[i] = find(parent[i]);
	}

	void Union(int a, int b) {
		int c = find(a);
		int d = find(b);
		if (c != d) {
			if (Size[c] > Size[d]) {
				swap(c, d);
			}
			parent[d] = c;
			Size[c] += Size[d];
		}
	}

	int spanningTree(int V, vector<vector<int>> adj[]) {
		for (int i = 0; i < V; i++) {
			make(i);
		}

		multiset<vector<int>> ms;
		for (int i = 0; i < V; i++) {
			for (auto &it : adj[i]) {
				int v = it[0], w = it[1];
				ms.insert({w, i, v}); // Store as {weight, u, v}
			}
		}

		int ans = 0;
		while (!ms.empty()) {
			auto it = *ms.begin();
			int w = it[0], u = it[1], v = it[2]; // ✅ Fixed order
			if (find(u) != find(v)) {
				Union(u, v);
				ans += w;
			}
			ms.erase(ms.begin());
		}

		return ans;
	}
};
