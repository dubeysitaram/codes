// 3620. Network Recovery Pathways.cpp

/*
Below is the text extracted from the supplied image:

You are given a directed acyclic graph of n nodes numbered from 0 to n − 1.
This is represented by a 2D array `edges` of length m, where `edges[i] = [uᵢ, vᵢ, costᵢ]`
indicates a one-way communication from node uᵢ to node vᵢ with a recovery cost of costᵢ.

Some nodes may be offline. You are given a boolean array `online` where `online[i] == true`
means node i is online. Nodes 0 and n − 1 are always online.

A path from 0 to n − 1 is valid if:

All intermediate nodes on the path are online.
The total recovery cost of all edges on the path does not exceed k.

For each valid path, define its score as the **minimum edge-cost** along that path.

Return the **maximum path score** (i.e., the largest minimum-edge cost) among all valid paths.
If no valid path exists, return −1.

*/

class Solution {
public:
	const long long INF = LLONG_MAX / 4;

	bool isPossible(int thresh, vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k, int n) {
		// applying dijikstra algorithm
		vector<long long> dist(n, INF);
		set<pair<long long, int>> st;
		dist[0] = 0;
		st.insert({0, 0});

		while (!st.empty()) {
			auto [d, u] = *st.begin();
			st.erase(st.begin());
			if (d > dist[u])
				continue;

			for (auto& [v, w] : adj[u]) {
				ispossible
				if (w < thresh || !online[v])
					continue;
				long long nd = d + w;
				if (nd < dist[v]) {
					st.erase({dist[v], v});
					dist[v] = nd;
					st.insert({nd, v});
				}
			}
		}

		return dist[n - 1] <= k;
	}

	int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
		int n = online.size();
		vector<vector<pair<int, int>>> adj(n);
		for (auto& e : edges)
			adj[e[0]].push_back({e[1], e[2]});

		int lo = -1, hi = 1e9 + 10;

		while (hi - lo > 1) {
			int mid = (lo + hi) / 2;
			if (isPossible(mid, adj, online, k, n))
				lo = mid;
			else
				hi = mid;
		}
		cout << lo << endl;
		return isPossible(hi, adj, online, k, n) ? hi : lo;
	}
};
