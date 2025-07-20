/*
You are given a 0-indexed array of integers nums, and an integer target.

Return the length of the longest subsequence of nums that sums up to target.
 If no such subsequence exists, return -1.

A subsequence is an array that can be derived from another array by
deleting some or no elements without changing the order of the remaining elements.

*/


class Solution {
public:
	int fn(int i, vector<int>& nums, int target,  vector<vector<int>>&dp) {
		int n = nums.size();
		if (target < 0)
			return INT_MIN >> 1;
		if (i >= n)
			return (target == 0) ? 0 : (INT_MIN >> 1);
		if (dp[i][target] != -1)return dp[i][target];
		int take = 1 + fn(i + 1, nums, target - nums[i], dp);
		int skip = fn(i + 1, nums, target, dp);

		return dp[i][target] = max(take, skip);
	}

	int lengthOfLongestSubsequence(vector<int>& nums, int target) {

		vector<vector<int>> dp(1001, vector<int>(1001, -1));
		int res = fn(0, nums, target, dp);
		return (res < 0) ? -1 : res;
	}
};

class Solution {
public:
	int lengthOfLongestSubsequence(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> dp(1001, vector<int>(1001, -1e5));
		dp[n][0] = 0;

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j <= target; j++) {
				if (j - nums[i] >= 0) {
					dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - nums[i]]);
				}
				dp[i][j] = max(dp[i][j], dp[i + 1][j]);
			}
		}

		return dp[0][target] < 0 ? -1 : dp[0][target];
	}
};
