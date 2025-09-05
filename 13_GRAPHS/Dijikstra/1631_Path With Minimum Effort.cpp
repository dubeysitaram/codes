/*1631. Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given heights,
a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col).
 You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell,
 (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right,
 and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.


Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

class Solution {
public:
	const int INF = 1e9;
	int minimumEffortPath(vector<vector<int>>& heights) {
		int n = heights.size(), m = heights[0].size();
		int X[4] = {1, 0, -1, 0};
		int Y[4] = {0, -1, 0, 1};
		multiset<pair<int, pair<int, int>>> ms;
		vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
		ms.insert({0, {0, 0}});
		dis[0][0] = 0;
		while (!ms.empty()) {
			auto it = ms.begin();
			int d = it->first;
			int x = it->second.first;
			int y = it->second.second;
			ms.erase(ms.begin());
			if (d > dis[x][y])
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + X[i];
				int ny = y + Y[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					int diff = abs(heights[nx][ny] - heights[x][y]);  // yaha thoda jyada dhyaan dena
					int neweffort = max(d, diff);
					if (neweffort < dis[nx][ny]) {
						ms.insert({neweffort, {nx, ny}});
						dis[nx][ny] = neweffort;
					}
				}
			}
		}
		return dis[n - 1][m - 1];
	}
};