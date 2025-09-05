/*
787. Cheapest Flights Within K Stops.cpp

There are n cities connected by some number of flights.
You are given an array flights where flights[i] = [fromi, toi, pricei]
indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k,
return the cheapest price from src to dst with at most k stops.
If there is no such route, return -1.
*/

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<pair<int, int>>> edges(n);
		for (int i = 0; i < flights.size(); i++) {
			int u = flights[i][0];
			int v = flights[i][1];
			int price = flights[i][2];
			edges[u].push_back({v, price});
		}
		vector<int> dis(n, INT_MAX);
		dis[src] = 0;
		queue<pair<pair<int, int>, int>> q;
		q.push({{0, 0}, src});
		while (!q.empty()) {
			auto it = q.front();
			int ct = it.first.first;
			int cost = it.first.second;
			int u = it.second;
			q.pop();
			if (ct > k)
				continue;
			for (auto [c, d] : edges[u]) {
				if (dis[c] > cost + d) {
					q.push({{ct + 1, cost + d}, c});
					dis[c] = cost + d;
				}
			}
		}
		return (dis[dst] == INT_MAX) ? -1 : dis[dst];
	}
};
