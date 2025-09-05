/* 2812. Find the Safest Path in a Grid
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid,
 including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell
in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|,
where |val| denotes the absolute value of val.

*/

class Solution {
public:
	int maximumSafenessFactor(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> wgrid(n, vector<int>(n, INT_MAX));
		queue<pair<int, int>> q;
		vector<vector<int>> vis(n, vector<int>(n, 0));

		// Multi-source BFS initialization: add all thieves to queue
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					vis[i][j] = 1;
					q.push({i, j});
					wgrid[i][j] = 0;
				}
			}
		}

		// Multi-source BFS to calculate minimum distance from any thief
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				pair<int, int> pp = q.front();
				q.pop();
				int x = pp.first;
				int y = pp.second;
				for (int d = 0; d < 4; d++) {
					int nx = dx[d] + x;
					int ny = dy[d] + y;
					if (nx < n && nx >= 0 && ny < n && ny >= 0 && !vis[nx][ny]) {
						wgrid[nx][ny] = wgrid[x][y] + 1;
						q.push({nx, ny});
						vis[nx][ny] = 1;
					}
				}
			}
		}

		// Dijkstra's variant to maximize minimum safeness along the path
		multiset<pair<int, pair<int, int>>> ms;
		ms.insert({wgrid[0][0], {0, 0}});
		vector<vector<int>> dis(n, vector<int>(n, INT_MIN));
		dis[0][0] = wgrid[0][0];

		while (!ms.empty()) {
			auto it = *ms.rbegin();
			int d = it.first;
			int x = it.second.first;
			int y = it.second.second;
			ms.erase(prev(ms.end()));

			if (d < dis[x][y])
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + x;
				int ny = dy[i] + y;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					int newsfactor = min(wgrid[nx][ny], d);
					if (dis[nx][ny] < newsfactor) {
						ms.erase({dis[nx][ny], {nx, ny}});
						ms.insert({newsfactor, {nx, ny}});
						dis[nx][ny] = newsfactor;
					}
				}
			}
		}

		return dis[n - 1][n - 1];
	}
};
