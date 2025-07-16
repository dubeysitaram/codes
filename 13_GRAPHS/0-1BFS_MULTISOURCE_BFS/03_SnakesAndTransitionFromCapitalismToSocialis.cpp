// MULTISOURCE BFS 
// 

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, { -1, 1}, { -1, -1}, {1, -1}, {1, 1}};

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

void solve() {
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	vector<vector<int>> level(n, vector<int>(m, 0));

	int max_ = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			max_ = max(max_, g[i][j]);
		}
	}

	queue<pair<int, int>> max_pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == max_) {
				max_pos.push({i, j});
				vis[i][j] = 1;
			}
		}
	}

	int ans = 0;
	while (!max_pos.empty()) {
		auto [u, v] = max_pos.front();
		max_pos.pop();
		for (auto [dx, dy] : moves) {
			int nu = u + dx;
			int nv = v + dy;
			if (isValid(nu, nv) && !vis[nu][nv]) {
				level[nu][nv] = level[u][v] + 1;
				max_pos.push({nu, nv});
				vis[nu][nv] = 1;
				ans = max(ans, level[nu][nv]);
			}
		}
	}

	cout << ans << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}


// ----------------------------------------------------------------------------original CODE BELOW
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<pair<int, int>> moves = {
	{0, 1}, {0, -1}, {1, 0}, { -1, 0},
	{ -1, 1}, { -1, -1}, {1, -1}, {1, 1}
};

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

void solve() {
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int> (m, 0));
	vector<vector<int>> vis(n, vector<int> (m, 0));
	vector<vector<int>> dp(n, vector<int> (m, 0));

	int max_ = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			max_ = max(max_, g[i][j]);
		}
	}

	queue<pair<int, int>> max_pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == max_) {
				max_pos.push({i, j});
				dp[i][j] = 0;
				vis[i][j] = 1;
			}
		}
	}

	int ans = 0;
	while (!max_pos.empty()) {
		pair<int, int> curr = max_pos.front();
		max_pos.pop();
		int v_x = curr.first, v_y = curr.second;

		for (pair<int, int> move : moves) {
			int x = move.first + v_x;
			int y = move.second + v_y;
			if (isValid(x, y) && !vis[x][y]) {
				max_pos.push({x, y});
				vis[x][y] = 1;
				dp[x][y] = dp[v_x][v_y] + 1;
				ans = max(ans, dp[x][y]);
			}
		}

	}
	cout << ans << endl;

}

signed main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
