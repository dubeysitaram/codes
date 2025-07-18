/*
You are given a 0-indexed integer array nums of even length consisting of
an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Constraints:

2 <= nums.length <= 2 * 105
nums.length is even
1 <= |nums[i]| <= 105
nums consists of equal number of positive and negative integers.
*/









class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans;
		vector<int> neg;
		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (nums[i] < 0)
				neg.push_back(nums[i]);
			else
				pos.push_back(nums[i]);
		}
		for (int i = 0; i < n / 2; i++) {
			ans.push_back(pos[i]);
			ans.push_back(neg[i]);
		}
		return ans;
	}
};