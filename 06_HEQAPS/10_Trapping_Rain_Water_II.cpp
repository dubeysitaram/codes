//407 Trapping_Rain_Water_II.cpp

/*
Given an m x n integer matrix heightMap
representing the height of each unit cell in a 2D elevation map,
return the volume of water it can trap after raining.
*/
class Solution {
public:
	typedef pair<int, pair<int, int>> pp;
	int trapRainWater(vector<vector<int>>& heightMap) {
		int m = heightMap.size(), n = heightMap[0].size();
		priority_queue<pp, vector<pp>, greater<>> pq;
		vector<vector<int>> vis(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			pq.push({heightMap[i][0], {i, 0}});
			vis[i][0] = 1;
			pq.push({heightMap[i][n - 1], {i, n - 1}});
			vis[i][n - 1] = 1;
		}
		for (int j = 1; j < n - 1; j++) {
			pq.push({heightMap[0][j], {0, j}});
			vis[0][j] = 1;
			pq.push({heightMap[m - 1][j], {m - 1, j}});
			vis[m - 1][j] = 1;
		}

		int amount = 0;
		int dirX[4] = {1, 0, -1, 0};
		int dirY[4] = {0, 1, 0, -1};
		while (!pq.empty()) {
			pp t = pq.top();
			int height = t.first;
			int x = t.second.first;
			int y = t.second.second;
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dirX[i];
				int ny = y + dirY[i];
				if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
					amount += max(0, height - heightMap[nx][ny]);
					pq.push({max(heightMap[nx][ny], height), {nx, ny}});
					vis[nx][ny] = 1;
				}
			}
		}
		return amount;
	}
};