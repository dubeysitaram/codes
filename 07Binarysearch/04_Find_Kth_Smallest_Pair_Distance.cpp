/*
Leetcode 719. Find K-th Smallest Pair Distance

The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k,
return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

*/



class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		auto ispossible = [&](int mid) {
			long long ct = 0;
			for (int i = 0; i < n; i++) {
				int x = upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + mid) - nums.begin();
				ct += x - (i + 1);
				if (ct >= k) return true;
			}
			return false;
		};
		int lo = -1, hi = nums.back() - nums.front();
		while (hi - lo > 1) {
			int mid = lo + (hi - lo) / 2;
			if (ispossible(mid)) hi = mid;
			else lo = mid;
		}
		return hi;
	}
};
