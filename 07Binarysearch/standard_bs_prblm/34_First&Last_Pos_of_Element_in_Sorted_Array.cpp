/* 34 First&Last_Pos_of_Element_in_Sorted_Array.cpp

Given an array of integers nums sorted in non - decreasing order,
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		auto it = lower_bound(nums.begin(), nums.end(), target);
		if (it == nums.end() || *it != target)
			return { -1, -1};
		int st = it - nums.begin();
		int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
		return {st, end - 1};
	}
};