
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.
 Notice that the solution set must not contain duplicate triplets.
*/

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	// we will iterate over array to skip the duplicates
	set<vector<int>> s;
	for (int i = 0; i < n - 1; i++) {
		if (i > 0 && nums[i] == nums[i - 1])i++;   // skip the duplicates
		int j = i + 1;
		int k = n - 1;
		int reqsum = 0 - nums[i];
		while (j < k) {
			if (nums[j] + nums[k] == reqsum) {
				vector<int> v = {nums[i], nums[j], nums[k]};
				s.insert(v);
				while (j < k && nums[j] == nums[j + 1])   // skip the duplicates
					j++;
				while (j < k && nums[k] == nums[k - 1])   // skip the duplicates
					k--;
				j++;
				k--;
			} else if (nums[j] + nums[k] > reqsum) {
				k--;
			} else {
				j++;
			}
		}
	}
	for (auto it : s) {
		ans.push_back(it);
	}
	return ans;
}