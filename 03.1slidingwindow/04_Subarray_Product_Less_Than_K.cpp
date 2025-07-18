/*
Given an array of integers nums and an integer k,
return the number of contiguous subarrays
where the product of all the elements in the subarray is strictly less than k.

*/
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k == 0 || k == 1)return 0;
		int i = 0;
		int j = 0;
		int prod = 1;
		int ct = 0;
		int n = nums.size();
		while (j < n) {
			prod *= nums[j];
			if (prod >= k) {
				while (prod >= k) {
					prod /= nums[i];
					i++;
				}
				if (prod == 1) {j++; continue;}
			}
			if (prod == 0) break;
			int add = j - i + 1;
			ct += add;
			j++;
		}
		return ct;
	}
};