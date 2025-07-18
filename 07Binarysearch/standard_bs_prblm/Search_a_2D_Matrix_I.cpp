/* LC 74
Search_a_2D_Matrix_I
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/
// 2 baar binary serach lagao 1 baar mai row fix karo then us row mai dearch krlo binary serahc laga ke
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(); int n = matrix[0].size();
		int lo1 = 0;
		int hi1 = n;
		int lo2 = 0;
		int hi2 = m;
		while (hi2 - lo2 > 1) {
			int mid = (hi2 + lo2) / 2;
			if (matrix[mid][0] > target) {
				hi2 = mid;
			} else
				lo2 = mid;
		}
		while (hi1 - lo1 > 1) {
			int mid = (hi1 + lo1) / 2;
			if (matrix[lo2][mid] > target) {
				hi1 = mid;
			} else
				lo1 = mid;
		}
		if (matrix[lo2][lo1] == target)return true;
		return false;
	}
};

// --------------------------------------------WORD SEARCH 1 AND 2 MAI SAME CODE CHALEGA------------------------------------------------------
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