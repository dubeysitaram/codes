/* 974. Subarray Sums Divisible by K

Given an integer array nums and an integer k,
return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
*/
class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		map<int, int> mp;
		int sum = 0, ans = 0;
		mp[0] = 1;
		int n = nums.size();
		// agar do array same modulo de rahe hai to unka differnce k se
		// divisible hoga
		for (int i = 0; i < n; i++) {
			sum = ((sum + nums[i]) % k + k) % k;
			if (mp.find(sum) != mp.end())
				ans += mp[sum];
			mp[sum]++;
		}

		return ans;
	}
};

