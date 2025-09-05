/*
174_Dungeon Game.cpp


given a grid of m*n  consisting of positive negative and 0 elements
if a element is positive then we can add to our energy
if 0 then it does not affect our energy
and if it is negative then it is taken from our body
then we have to find minimum initial energy required in order to reach from to left to bottom right
*/

// 

class Solution {
public:
	int m, n;
	int dp[201][201];

	int fn(int i, int j, vector<vector<int>>& matrix) {
		if (i >= m || j >= n)
			return INT_MAX;

		if (dp[i][j] != -1)
			return dp[i][j];

		if (i == m - 1 && j == n - 1) {
			return max(1, 1 - matrix[i][j]);
		}

		int right = fn(i, j + 1, matrix);
		int down = fn(i + 1, j, matrix);

		int need = min(right, down) - matrix[i][j];
		return dp[i][j] = max(1, need);
	}

	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		m = dungeon.size(), n = dungeon[0].size();
		memset(dp, -1, sizeof(dp));
		return fn(0, 0, dungeon);
	}
};
