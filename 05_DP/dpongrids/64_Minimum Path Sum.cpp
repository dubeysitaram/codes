/*64_Minimum Path Sum.cpp
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

class Solution {
public:
	int solve(int i, int j, int m, int n, vector<vector<int>>& grid,
	          vector<vector<int>>& dp) {
		if (i >= m || j >= n)
			return INT_MAX >> 1;
		if (i == m - 1 && j == n - 1)
			return grid[i][j];

		if (dp[i][j] != -1)
			return dp[i][j];

		int ans = INT_MAX;
		ans = min(ans, grid[i][j] + solve(i + 1, j, m, n, grid, dp));
		ans = min(ans, grid[i][j] + solve(i, j + 1, m, n, grid, dp));
		return dp[i][j] = ans;
	}
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		return solve(0, 0, m, n, grid, dp);
	}
};