// 410_Split Array Largest Sum.cpp
/*
Given an integer array nums and an integer k,
split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

*/

class Solution {
public:
	bool blackbox(vector<int>& arr, int k, int mid) {
		int tempsum = 0;
		int ct = 1;
		for (int i = 0; i < arr.size(); i++) {
			if (tempsum + arr[i] <= mid) {
				tempsum = tempsum + arr[i];
			} else {
				tempsum = arr[i];
				ct++;
			}
		}

		if (ct <= k)
			return true;
		else
			return false;
	}

	int splitArray(vector<int>& nums, int k) {
		int lo = *max_element(nums.begin(), nums.end());
		int hi = 1e9;
		// accumulate(nums.begin(),nums.end(),0);
		while (hi - lo > 1) {
			// debug(hi);debug(lo);
			int mid = (hi + lo) / 2;
			//   debug(mid);
			if (blackbox(nums, k, mid)) {
				hi = mid;
			} else
				lo = mid;
		}
		if (blackbox(nums, k, lo))
			return lo;
		return hi;
	}
};