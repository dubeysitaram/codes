/*
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.


Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

*/

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int x = 0;
		int n = nums.size();
		// concept==> (1^2^3......^n) = let say x;
		// if we xor each element at left and right both
		// same same will go to zero and left over is the missing and it value is at right
		// (x^y)^x  = ans
		for (int i = 1; i <= n; i++) {
			x = x ^ i;
			x = x ^ nums[i - 1];
		}
		return x;
	}
};