/*
 1976. Number of Ways to Arrive at Destination.cpp
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional
roads between some intersections. The inputs are generated such that you can reach any intersection
from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei]
means that there is a road between intersections ui and vi that takes timei minutes to travel.
You want to know in how many ways you can travel from intersection 0 to intersection n - 1
in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time.
 Since the answer may be large, return it modulo 109 + 7.

*/
class Solution {
public:
	typedef long long ll;
	const ll MOD = 1e9 + 7;
	ll solve(vector<vector<pair<ll, ll>>>& g, ll n) {
		vector<ll> dis(n, LLONG_MAX);
		multiset<pair<ll, ll>> ms;
		ms.insert({0, 0});
		dis[0] = 0;
		vector<ll> dp(n, 0);
		dp[0] = 1;
		while (!ms.empty()) {
			auto it = *ms.begin();
			ll d = it.first;
			ll u = it.second;
			ms.erase(ms.begin());
			if (dis[u] < d)
				continue;
			for (auto [v, c] : g[u]) {
				if (dis[v] > d + c) {
					ms.erase({dis[v], v});
					dis[v] = d + c;
					dp[v] = dp[u] % MOD;
					ms.insert({dis[v], v});

				} else if (dis[v] == d + c) {
					dp[v] = (dp[v] + dp[u]) % MOD;
				}
			}
		}
		return dp[n - 1];
	}

	ll countPaths(int n, vector<vector<int>>& roads) {
		vector<vector<pair<ll, ll>>> g(n);
		for (auto& road : roads) {
			ll u = road[0], v = road[1], d = road[2];
			g[u].push_back({v, d});
			g[v].push_back({u, d});
		}
		ll ans = solve(g, n);
		return ans;
	}
};
