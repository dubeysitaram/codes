
// Given an integer array nums, find the subarray with the largest sum, and return its sum.


class Solution {
public:
	int sum = INT_MIN; int temp = 0;

	int maxSubArray(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			temp += nums[i];
			sum = max(sum, temp);
			if (temp < 0)temp = 0;
		}

		return sum;
	}

};