// 3613. Minimize Maximum Component Cost

/*
You are given an undirected connected graph with n nodes labeled from 0 to n - 1
and a 2D integer array edges where edges[i] = [ui, vi, wi] denotes an undirected
edge between node ui and node vi with weight wi, and an integer k.

You are allowed to remove any number of edges from the graph such that the
resulting graph has at most k connected components.

The cost of a component is defined as the maximum edge weight in that component.
If a component has no edges, its cost is 0.

Return the minimum possible value of the maximum cost among all components after
such removals.
*/


// minimum spanning tree approach
class Solution {
public:
	static const int N = 1e5 + 5;
	int parent[N], Size[N];

	void make(int v) {
		parent[v] = v;
		Size[v] = 1;
	}

	int find(int v) {
		if (parent[v] == v) return v;
		return parent[v] = find(parent[v]);
	}

	void Union(int a, int b) {
		int ra = find(a);
		int rb = find(b);
		if (ra != rb) {
			if (Size[rb] > Size[ra])
				swap(ra, rb);
			parent[rb] = ra;
			Size[ra] += Size[rb];
		}
	}

	int minCost(int n, vector<vector<int>>& edges, int k) {
		for (int i = 0; i < n; i++) make(i);
		sort(edges.begin(), edges.end(), [](auto & a, auto & b) {
			return a[2] < b[2];
		});

		vector<int> mstEdges;

		for (auto &e : edges) {
			int u = e[0], v = e[1], w = e[2];
			if (find(u) != find(v)) {
				Union(u, v);
				mstEdges.push_back(w);
			}
		}

		int comps = 1;
		int sz = mstEdges.size();
		// remove k-1 largest edges from MST
		sort(mstEdges.begin(), mstEdges.end(), greater<int>());
		while (comps < k && !mstEdges.empty()) {
			mstEdges.erase(mstEdges.begin());
			comps++;
		}

		return mstEdges.empty() ? 0 : mstEdges[0];
	}
};
// binary search +DSU

class Solution {
public:
	static const int N = 1e5 + 5;
	int parent[N], Size[N];

	void make(int v) {
		parent[v] = v;
		Size[v] = 1;
	}

	int find(int v) {
		if (parent[v] == v) return v;
		return parent[v] = find(parent[v]);
	}

	void Union(int a, int b) {
		int ra = find(a);
		int rb = find(b);
		if (ra != rb) {
			if (Size[rb] > Size[ra]) swap(ra, rb);
			parent[rb] = ra;
			Size[ra] += Size[rb];
		}
	}

	bool isPossible(int maxW, vector<vector<int>>& edges, int n, int k) {
		for (int i = 0; i < n; i++) make(i);

		for (auto &e : edges) {
			if (e[2] <= maxW) {
				Union(e[0], e[1]);
			}
		}

		unordered_set<int> components;
		for (int i = 0; i < n; i++) {
			components.insert(find(i));
		}

		return components.size() <= k;
	}

	int minCost(int n, vector<vector<int>>& edges, int k) {
		int lo = -1, hi = 1e6;

		while (hi - lo > 1) {
			int mid = (lo + hi) / 2;
			if (isPossible(mid, edges, n, k)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		return hi;
	}
};

