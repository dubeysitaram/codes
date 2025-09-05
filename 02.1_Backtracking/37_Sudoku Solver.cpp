/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


*/

class Solution {
public:
	bool check(int val, int x, int y, vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			if (board[i][y] == val + '0')
				return false;
		}
		for (int j = 0; j < 9; j++) {
			if (board[x][j] == val + '0')
				return false;
		}
		int a = (x / 3) * 3;
		int b = (y / 3) * 3;
		for (int i = a; i < a + 3; i++) {
			for (int j = b; j < b + 3; j++) {
				if (board[i][j] == val + '0')
					return false;
			}
		}
		return true;
	}
	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					for (int val = 1; val <= 9; val++) {
						if (check(val, i, j, board)) {
							board[i][j] = val + '0';
							if (solve(board)) {
								return true;
							}
							board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
};