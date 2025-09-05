/*36_Valid Sudoku.cpp


Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

*/
class Solution {
public:
	bool check(char val, int x, int y, vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			if (i == x)continue;
			if (board[i][y] == val )
				return false;
		}
		for (int j = 0; j < 9; j++) {
			if (j == y)continue;
			if (board[x][j] == val )
				return false;
		}
		int a = (x / 3) * 3;
		int b = (y / 3) * 3;
		for (int i = a; i < a + 3; i++) {
			for (int j = b; j < b + 3; j++) {
				if (i == x && j == y)continue;
				if (board[i][j] == val )
					return false;
			}
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && check(board[i][j], i, j, board) == false)return false;
			}
		}
		return  true;
	}
};