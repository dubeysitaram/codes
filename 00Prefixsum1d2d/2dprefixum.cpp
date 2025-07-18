#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

	// Input matrix (1-based)
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> mat[i][j];

	// Build prefix sum matrix
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			prefix[i][j] = mat[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];

	// Number of queries
	int q;
	cin >> q;
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		int sum = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
		cout << sum << "\n";
	}

	return 0;
}
