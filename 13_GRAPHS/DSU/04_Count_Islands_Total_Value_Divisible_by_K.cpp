/*

3619. Count Islands With Total Value Divisible by K

You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers
(representing land) that are 4-directionally connected (horizontally or vertically).

The total value of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value divisible by k.


*/

class Solution {
public:
	static const int N = 1000005;
	int parent[N], Size[N];

	void make(int v) {
		parent[v] = v;
		Size[v] = 1;
	}

	int find(int v) {
		return parent[v] == v ? v : parent[v] = find(parent[v]);
	}

	void Union(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			if (Size[b] > Size[a]) swap(a, b);
			parent[b] = a;
			Size[a] += Size[b];
		}
	}

	int countIslands(vector<vector<int>>& grid, int k) {
		long long m = grid.size(), n = m ? grid[0].size() : 0;
		long long total = m * n;
		for (long long i = 0; i < total; ++i) make(i);

		long long dirX[4] = {1, 0, -1, 0}, dirY[4] = {0, -1, 0, 1};
		for (long long i = 0; i < m; ++i) {
			for (long long j = 0; j < n; ++j) {
				if (grid[i][j] > 0) {
					long long id = i * n + j;
					for (long long d = 0; d < 4; ++d) {
						long long ni = i + dirX[d], nj = j + dirY[d];
						if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > 0)
							Union(id, ni * n + nj);
					}
				}
			}
		}

		unordered_map<long long, long long> compsum;
		compSum.reserve(total);
		for (long long i = 0; i < m; ++i) {
			for (long long j = 0; j < n; ++j) {
				if (grid[i][j] > 0)
					compsum[find(i * n + j)] += grid[i][j];
			}
		}

		long long count = 0;
		for (auto& [root, sum] : compsum)
			if (sum % k == 0)
				++count;

		return count;
	}
};
