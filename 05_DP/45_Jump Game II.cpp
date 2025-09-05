/*45_Jump Game II.cpp
You are given a 0-indexed array of integers nums of length n.
You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i.
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1].
The test cases are generated such that you can reach nums[n - 1].
*/
class Solution {
public:
	int dp[10004];
	int fn(int i, vector<int>& nums) {
		int n = nums.size();
		if (i >= n - 1)return 0;
		if (dp[i] != -1)return dp[i];
		int ans = 1e9;
		for (int j = 1; j <= nums[i]; j++) {
			ans = min(ans, 1 + fn(i + j, nums));
		}
		return dp[i] = ans;
	}
	int jump(vector<int>& nums) {
		memset(dp, -1, sizeof(dp));
		return fn(0, nums);
	}
};