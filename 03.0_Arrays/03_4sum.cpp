/*

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

*/



// 1.  brute force o(n4)

// optimal

// fixing i and j moving k and searching last in between of the j and k
// and using the set so that the repetition is not there
vector<vector<int>> fourSum(vector<int>& nums,  int target) {
	// sort(nums.begin(), nums.end());
	long long n = nums.size();
	set<vector<int>> ans;
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n; j++) {
			unordered_set<long long>s;// to store the unique element in b/w the j and k indexs
			for (long long k = j + 1; k < n; ++k) {
				long long sum = 0LL + nums[i] + nums[j] + nums[k];
				long long reqlast = target - sum;
				if (s.find(reqlast) != s.end()) {
					vector<int>valid = {int(nums[i]), int(nums[j]), int(nums[k]), int(reqlast)};
					sort(valid.begin(), valid.end());
					ans.insert(valid);
				}
				s.insert(nums[k]);
			}
		}
	}
	vector<vector<int>> finalans;
	for (auto it : ans) {
		finalans.push_back(it);
	}
	return finalans;
}



// optimal solution

// using the  reqsum =  target - nums[i]-nums[j] and
// searching for the req sum from the index k = j+1 to l = n-1 using the two pointer
//  as we did in 3sum

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> finalans;
	sort(nums.begin(), nums.end());
	int n = nums.size();

	for (int i = 0; i < n; i++) {
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		for (int j = i + 1; j < n; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;

			long long reqsum = (long long)target - nums[i] - nums[j];
			int k = j + 1;
			int l = n - 1;

			while (k < l) {
				long long sum2 = nums[k] + nums[l];
				if (sum2 == reqsum) {
					finalans.push_back({nums[i], nums[j], nums[k], nums[l]});
					while (k < l && nums[k] == nums[k + 1]) k++;
					while (k < l && nums[l] == nums[l - 1]) l--;
					k++;
					l--;
				} else if (sum2 < reqsum) {
					k++;
				} else {
					l--;
				}
			}
		}
	}
	return finalans;
}
