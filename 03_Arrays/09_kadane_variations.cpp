/*
Given an integer array nums, 
return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/




class Solution {
public:

	vector<int> productExceptSelf(vector<int>& nums) {
		int ans = 1;
		int n = nums.size();
		vector<int>v1(n);
		vector<int>v2(n);
		for (int i = 0; i < nums.size(); i++) {
			v1[i] = ans;
			ans *= nums[i];

		}
		ans = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			v2[i] = ans;
			ans *= nums[i];

		}
		for (int i = 0; i < nums.size(); i++) {
			nums[i] = v1[i] * v2[i];
		}
		return nums;
	}
};