/*
3202. Find the Maximum Length of Valid Subsequence II


You are given an integer array nums and a positive integer k.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
Return the length of the longest valid subsequence of nums.

Constraints:

2 <= nums.length <= 103
1 <= nums[i] <= 107
1 <= k <= 103


*/

class Solution {
public:
	int maximumLength(vector<int>& nums, int k) {
		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(k, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				int mod = (nums[i] + nums[j]) % k;
				dp[i][mod] = max(dp[i][mod], 1 + dp[j][mod]);
			}
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				ans = max(ans, dp[i][j]);
			}
		}
		return ans + 1;
	}
};