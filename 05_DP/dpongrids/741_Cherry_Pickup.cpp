// 741_Cherry_Pickup.cpp
/*
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1)
by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

*/

// 2 logo ko 0,0 se m-1,n-1 tak chala do 2*2 cases banege

class Solution {
public:
	int m, n;
	int dp[51][51][51][51];
	int fn(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {
		if (i1 >= m || j1 >= n || i2 >= m || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)return -1e9;
		if (i1 == m - 1 && j1 == n - 1 && i2 == m - 1 && j2 == n - 1)return grid[i1][j1];

		if (dp[i1][i2][j1][j2] != -1)return dp[i1][i2][j1][j2];

		int ans = -1e9;
		if (i1 == i2 && j1 == j2) {
			int x = grid[i1][j1];
			grid[i1][j1] = 0;
			ans = max(ans, x + fn(i1 + 1, j1, i2 + 1, j2, grid));
			ans = max(ans, x + fn(i1 + 1, j1, i2, j2 + 1, grid));
			ans = max(ans, x + fn(i1, j1 + 1, i2 + 1, j2, grid));
			ans = max(ans, x + fn(i1, j1 + 1, i2, j2 + 1, grid));
			grid[i1][j1] = x;
		} else {
			int x = grid[i1][j1], y = grid[i2][j2];
			grid[i1][j1] = 0;
			grid[i2][j2] = 0;
			ans = max(ans, x + y + fn(i1 + 1, j1, i2 + 1, j2, grid));
			ans = max(ans, x + y + fn(i1 + 1, j1, i2, j2 + 1, grid));
			ans = max(ans, x + y + fn(i1, j1 + 1, i2 + 1, j2, grid));
			ans = max(ans, x + y + fn(i1, j1 + 1, i2, j2 + 1, grid));
			grid[i1][j1] = x;
			grid[i2][j2] = y;
		}
		return dp[i1][i2][j1][j2] = ans;
	}

	int cherryPickup(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		memset(dp, -1, sizeof(dp));
		return max(0, fn(0, 0, 0, 0, grid));
	}
};


//  optimized way


class Solution {
public:
	int m, n;
	int dp[51][51][51];

	int fn(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {
		j2 = i1 + j1 - i2;
		if (i1 >= m || j1 >= n || i2 >= m || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)return -1e9;
		if (i1 == m - 1 && j1 == n - 1 && i2 == m - 1 && j2 == n - 1)return grid[i1][j1];

		if (dp[i1][j1][i2] != -1)return dp[i1][j1][i2];

		int ans = -1e9;
		if (i1 == i2 && j1 == j2) {
			int x = grid[i1][j1];
			ans = max(ans, x + fn(i1 + 1, j1, i2 + 1, j2, grid));
			ans = max(ans, x + fn(i1 + 1, j1, i2, j2 + 1, grid));
			ans = max(ans, x + fn(i1, j1 + 1, i2 + 1, j2, grid));
			ans = max(ans, x + fn(i1, j1 + 1, i2, j2 + 1, grid));
		} else {
			int x = grid[i1][j1], y = grid[i2][j2];
			ans = max(ans, x + y + fn(i1 + 1, j1, i2 + 1, j2, grid));
			ans = max(ans, x + y + fn(i1 + 1, j1, i2, j2 + 1, grid));
			ans = max(ans, x + y + fn(i1, j1 + 1, i2 + 1, j2, grid));
			ans = max(ans, x + y + fn(i1, j1 + 1, i2, j2 + 1, grid));
		}
		return dp[i1][j1][i2] = ans;
	}

	int cherryPickup(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		memset(dp, -1, sizeof(dp));
		return max(0, fn(0, 0, 0, 0, grid));
	}
};
