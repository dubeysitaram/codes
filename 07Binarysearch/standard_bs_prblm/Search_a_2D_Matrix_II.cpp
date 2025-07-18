// LC 240 Search_a_2D_Matrix_II.cpp
/*

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();

		for (int i = 0; i < m; i++) {
			int hi = n;
			int lo = 0;
			while (hi - lo > 1) {
				int mid = (hi + lo) / 2;
				if (matrix[i][mid] > target) {
					hi = mid;
				} else
					lo = mid;
			}
			if (matrix[i][lo] == target)
				return true;
		}
		return false;
	}
};

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int i = 0, j = n - 1;
		while (i < m && j >= 0) {
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] > target) j--;
			else i++;
		}
		return false;
	}
};