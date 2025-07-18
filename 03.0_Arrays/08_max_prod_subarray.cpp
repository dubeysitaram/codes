
// variation of kadane

/*
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

*/

class Solution {
public:

	int maxProduct(vector<int>& nums) {
		double prod = INT_MIN; double temp = 1;
		for (int i = 0; i < nums.size(); i++) {
			temp *= nums[i];
			prod = max(prod, temp);
			if (temp == 0)temp = 1;
		}
		temp = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			temp *= nums[i];
			prod = max(prod, temp);
			if (temp == 0)temp = 1;
		}
		return int(prod);
	}
};