/*
You are given a 0-indexed integer array nums and an integer p.
Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized.
Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j,
the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs.
We define the maximum of an empty set to be zero.

*/




class Solution {
public:
	bool ispossible(vector<int>& nums, int mid, int p) {
		int ct = 0;
		for (int i = 0; i < nums.size() - 1;) {
			if (nums[i + 1] - nums[i] <= mid) {
				ct++;
				i += 2;
			} else {
				i++;
			}
		}
		return ct >= p;
	}

	int minimizeMax(vector<int>& nums, int p) {
		sort(nums.begin(), nums.end());
		int lo = 0, hi = 1e9;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (ispossible(nums, mid, p)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		return ispossible(nums, lo, p) ? lo : hi;
	}
};
