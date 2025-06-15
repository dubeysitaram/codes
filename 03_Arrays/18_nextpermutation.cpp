class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		if (n == 1 || n == 0)
			return;
		int j = n - 2;
		while (j >= 0 && nums[j] >= nums[j + 1])
			j--;
		if (j < 0) {
			sort(nums.begin(), nums.end());
			return;
		}
		int i = n - 1;
		while (nums[i] <= nums[j])
			i--;

		swap(nums[i], nums[j]);
		sort(nums.begin() + j + 1, nums.end());
		return;
	}
};