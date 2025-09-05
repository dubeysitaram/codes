/*1594_Maximum Non Negative Product in a Matrix.cpp
You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0),
and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and
ending in the bottom-right corner (m - 1, n - 1),
find the path with the maximum non-negative product.
The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

Notice that the modulo is performed after getting the maximum product.

*/



class Solution {
public:
	typedef long long ll;
	ll m, n;
	const ll MOD = 1e9 + 7;

	pair<ll, ll> fn(ll i, ll j, vector<vector<int>>& grid, vector<vector<pair<ll, ll>>>& dp) {
		if (i == m - 1 && j == n - 1)
			return {grid[i][j], grid[i][j]};
		if (dp[i][j].first != -1)
			return dp[i][j];

		ll maxval = -1e18, minval = 1e18;

		if (i + 1 < m) {
			pair<ll, ll> down = fn(i + 1, j, grid, dp);
			maxval = max({maxval, grid[i][j] * down.first, grid[i][j] * down.second});
			minval = min({minval, grid[i][j] * down.first, grid[i][j] * down.second});
		}

		if (j + 1 < n) {
			pair<ll, ll> right = fn(i, j + 1, grid, dp);
			maxval = max({maxval, grid[i][j] * right.first, grid[i][j] * right.second});
			minval = min({minval, grid[i][j] * right.first, grid[i][j] * right.second});
		}

		return dp[i][j] = {maxval, minval};
	}

	int maxProductPath(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n, { -1, -1}));
		pair<ll, ll> ans = fn(0, 0, grid, dp);
		return (ans.first < 0) ? -1 : ans.first % MOD;
	}
};
