/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/


/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
*/



class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		int flag1 = 0, flag2 = 0;

		// pehli row mai koi zero to nhi hai kyu ki baad mai puri row ko zero karna padega kta hai
		// as we ware lifting all matriz zero to first column and first row
		for (int i = 0; i < n; i++) {
			if (matrix[i][0] == 0) {
				flag2 = 1;
			}
		}

		for (int i = 0; i < m; i++) {
			if (matrix[0][i] == 0) {
				flag1 = 1;
			}
		}
		// if any zero is found we are setting corresponding row and column in the first row and column equal to zero
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		// now if zero is found in the first row set entire column to zero (do this for whole row)
		for (int j = 1; j < m; j++) {

			if (matrix[0][j] == 0) {
				for (int i = 0; i < n; i++) {
					matrix[i][j] = 0;
				}
			}
		}
		// now if zero is found in the first col set entire row to zero (do this for whole col)
		for (int i = 1; i < n; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 0; j < m; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		// if flag1 was 1 means zero was present in the first row so set the entire row = 0
		if (flag1 == 1) {
			for (int i = 0; i < m; i++) {
				matrix[0][i] = 0;
			}
		}
		// if flag2 was 1 means zero was present in the first col so set the entire col = 0
		if (flag2 == 1) {
			for (int i = 0; i < n; i++) {
				matrix[i][0] = 0;
			}
		}

	}
};