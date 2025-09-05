/*
3381. Maximum Subarray Sum With Length Divisible by K
You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.
*/

class Solution {
public:
	long long maxSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		long long sum = 0, ans = LLONG_MIN;
		map<int, multiset<long long>> mp;
		mp[0].insert(0);

		for (int i = 0; i < n; i++) {
			sum += nums[i];
			int rem = (i + 1) % k;

			if (mp.find(rem) != mp.end()) {
				ans = max(ans, sum - *mp[rem].begin());
			}

			mp[rem].insert(sum);
		}

		return ans;
	}
};


