// 44. Wildcard Matching.cpp
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

*/


class Solution {
public:
	bool fn(string &s, string &p, int i, int j, int n, int m, vector<vector<int>>& dp) {
		if (j == m)
			return i == n;
		if (i > n || j > m)
			return false;
		if (dp[i][j] != -1)
			return dp[i][j];

		bool ans = false;
		if (i < n && j < m && (s[i] == p[j] || p[j] == '?')) {
			ans |= fn(s, p, i + 1, j + 1, n, m, dp);
		} else {
			if (p[j] == '*') {
				ans |= fn(s, p, i, j + 1, n, m, dp);
				ans |= fn(s, p, i + 1, j, n, m, dp);
				ans |= fn(s, p, i + 1, j + 1, n, m, dp);
			} else {
				return false;
			}
		}
		return dp[i][j] = ans;
	}
	bool isMatch(string s, string p) {
		int n = s.size();
		int m = p.size();
		cout << n << " " << m << endl;
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
		return fn(s, p, 0, 0, n, m, dp);
	}
};