// 2435_Paths_in_Mat_Sum_Div_by_K.cpp

/*
You are given a 0-indexed m x n integer matrix grid and an integer k.
You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k.
Since the answer may be very large, return it modulo 109 + 7.


*/



class Solution {
public:
	const int MOD = 1e9 + 7;
	int m, n;
	int fn(int i, int j, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int k, int sum) {
		if (i >= m || j >= n)
			return 0;
		if (i == m - 1 && j == n - 1) {
			sum += grid[i][j] % k;
			if (sum % k == 0)
				return 1;
			return 0;
		}
		if (dp[i][j][sum] != -1)
			return dp[i][j][sum];
		int ans = 0;
		ans = (ans + fn(i + 1, j, grid, dp, k, (sum + (grid[i][j]) % k) % k) % MOD) % MOD;
		ans = (ans + fn(i, j + 1, grid, dp, k, (sum + (grid[i][j]) % k) % k) % MOD) % MOD;
		return dp[i][j][sum] = ans;
	}
	int numberOfPaths(vector<vector<int>>& grid, int k) {
		m = grid.size();
		n = grid[0].size();
		int sum = 0;
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
		return fn(0, 0, grid, dp, k, sum);
	}
};