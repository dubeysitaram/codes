// 05_Longest Palindromic Substring.cpp


class Solution {
public:
    int fn(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) {
            dp[i][j] = fn(i + 1, j - 1, s, dp);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (fn(i, j, s, dp) == 1) {// no need of doing substr again and again
                    if (j - i + 1 > maxLen) {
                        start = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
