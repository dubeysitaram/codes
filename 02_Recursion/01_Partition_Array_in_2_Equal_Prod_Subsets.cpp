/*
You are given an integer array nums containing distinct positive integers and an integer target.

Determine if you can partition nums into two non-empty disjoint subsets,
with each element belonging to exactly one subset,
such that the product of the elements in each subset is equal to target.

Return true if such a partition exists and false otherwise.

A subset of an array is a selection of elements of the array.
*/


class Solution {
public:
	bool fn(int i, vector<int>& nums, long long target, long long p1,
	        long long p2) {
		if (p1 > target || p2 > target)
			return false;
		if (i == nums.size()) {
			if (p1 == target && p2 == target)
				return true;
			else
				return false;
		}
		bool ans = false;
		ans |= fn(i + 1, nums, target, p1 * nums[i], p2);  // multiplying with the subset1 product
		ans |= fn(i + 1, nums, target, p1, p2 * nums[i]);  // multiplying with the subset1 product
		return ans;
	}
	bool checkEqualPartitions(vector<int>& nums, long long target) {
		return fn(0, nums, target, 1, 1);
	}
};