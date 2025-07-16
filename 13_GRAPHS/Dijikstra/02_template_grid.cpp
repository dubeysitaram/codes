#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[] = { -1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

vector<vector<int>> dijkstraGrid(const vector<vector<int>> &grid) {
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> dist(n, vector<int>(m, INF));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	set<pair<int, pair<int, int>>> st;  // {cost, {x, y}}

	dist[0][0] = grid[0][0];
	st.insert({dist[0][0], {0, 0}});

	while (!st.empty()) {
		auto [d, cell] = *st.begin();
		auto [x, y] = cell;
		st.erase(st.begin());

		if (vis[x][y]) continue;
		vis[x][y] = 1;

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				int newDist = d + grid[nx][ny];
				if (newDist < dist[nx][ny]) {
					dist[nx][ny] = newDist;
					st.insert({newDist, {nx, ny}});
				}
			}
		}
	}
	return dist;
}
