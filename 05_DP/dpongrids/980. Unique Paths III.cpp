/*980. Unique Paths III.cpp

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square,
that walk over every non-obstacle square exactly once.




*/
// yaha par is line ope dhayn dena hai {that walk over every non-obstacle square exactly once.}

class Solution {
public:
	int x[4] = {1, 0, -1, 0};
	int y[4] = {0, 1, 0, -1};

	int fn(int i, int j, int m, int n, vector<vector<int>>& grid, int tot, vector<vector<int>>& vis, int& ct) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || vis[i][j] != 0) {
			return 0;
		}
		if (grid[i][j] == 2) return ct == tot ? 1 : 0;

		vis[i][j] = 1;
		if (grid[i][j] == 0) ct++;

		int ans = 0;
		for (int d = 0; d < 4; d++) {
			ans += fn(i + x[d], j + y[d], m, n, grid, tot, vis, ct);
		}

		vis[i][j] = 0;
		if (grid[i][j] == 0) ct--;

		return ans;
	}

	int uniquePathsIII(vector<vector<int>>& grid) {
		int tot = 0, m = grid.size(), n = grid[0].size(), s_x = -1, s_y = -1, ct = 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0) tot++;
				if (grid[i][j] == 1) {
					s_x = i; s_y = j;
				}
			}
		}

		vector<vector<int>> vis(m, vector<int>(n, 0));
		return fn(s_x, s_y, m, n, grid, tot, vis, ct);
	}

};