/*

417. Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
The Pacific Ocean touches the island's left and top edges.
and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells.
 You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level
  of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north,
 south, east, and west if the neighboring cell's height is less than or equal to the current cell's height.
  Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.



*/

#define pb push_back

class Solution {
public:
	int dirX[4] = {1, 0, -1, 0};
	int dirY[4] = {0, 1, 0, -1};
	int m, n;

	void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& heights) {
		vis[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dirX[i];
			int ny = y + dirY[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
			        !vis[nx][ny] && heights[nx][ny] >= heights[x][y]) {
				dfs(nx, ny, vis, heights);
			}
		}
	}

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		n = heights.size(), m = heights[0].size();
		vector<vector<int>> pac(n, vector<int>(m, 0));
		vector<vector<int>> atl(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++) {
			dfs(i, 0, pac, heights);         // Pacific Left
			dfs(i, m - 1, atl, heights);     // Atlantic Right
		}
		for (int j = 0; j < m; j++) {
			dfs(0, j, pac, heights);         // Pacific Top
			dfs(n - 1, j, atl, heights);     // Atlantic Bottom
		}

		vector<vector<int>> res;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (pac[i][j] && atl[i][j]) /// pani ka flow dono  ocean mai aana chaiye
					res.pb({i, j});
		return res;
	}
};
