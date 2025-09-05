/* 556. Next Greater Element III
Given a positive integer n, find the smallest integer which has exactly the same digits
existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer,
if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/

class Solution {
public:
	int nextPermutation(vector<int>& nums) {
		int n  = nums.size();
		int i = n - 2;
		while (i >= 0 && nums[i] >= nums[i + 1])i--;
		if (i < 0) {
			sort(nums.begin(), nums.end());
			return -1;
		}
		int j = n - 1;
		while (j > i) {
			if (nums[j] > nums[i])break;
			j--;
		}
		swap(nums[i], nums[j]);
		sort(nums.begin() + i + 1, nums.end());
		return 1;

	}
	int nextGreaterElement(int n) {
		int orig = n;
		vector<int> nums;
		while (n) {
			nums.push_back(n % 10);
			n = n / 10;
		}
		reverse(nums.begin(), nums.end());

		int y = nextPermutation(nums);
		if (y == -1)return y;



		long long ans = 0;
		for (int i = 0; i < (int)nums.size(); i++) {
			ans = ans * 10 + nums[i];
		}

		return (ans > INT_MAX) ? -1 : (int)ans;
	}
};
