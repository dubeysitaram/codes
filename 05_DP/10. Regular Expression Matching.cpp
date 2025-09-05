// 10. Regular Expression Matching.cpp
/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

*/


class Solution {
public:
	bool fn(string &s, string &p, int i, int j, int n, int m, vector<vector<int>>&dp) {
		if (j == m)
			return i == n;
		if (dp[i][j] != -1)return dp[i][j];
		bool ans = false;

		if (i < n && j < m && (s[i] == p[j] || p[j] == '.')) {
			if (j + 1 < m && p[j + 1] == '*') {
				ans |= fn(s, p, i + 1, j, n, m, dp);
				ans |= fn(s, p, i, j + 2, n, m, dp);
			} else {
				ans |= fn(s, p, i + 1, j + 1, n, m, dp);
			}
		} else {
			if (j + 1 < m && p[j + 1] == '*') {
				ans |= fn(s, p, i, j + 2, n, m, dp);
			} else {
				return false;
			}
		}

		return dp[i][j] = ans;
	}

	bool isMatch(string s, string p) {
		int n = s.size(); int m = p.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
		return fn(s, p, 0, 0, n, m, dp);
	}
};
