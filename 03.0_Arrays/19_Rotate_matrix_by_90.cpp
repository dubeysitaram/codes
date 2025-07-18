class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int j = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				swap(matrix[j][i], matrix[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
	}
};