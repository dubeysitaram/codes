/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n,
return the number of tuples (i, j, k, l) such that:
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/


//approach we will store the freq of nums[i]+nums[j];
// and then we will search for reqsum = target(0) - nums[i]-nums[j]

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	unordered_map<int, int> mp;
	int n1 = nums1.size(), n2 = nums2.size(), n3 = nums3.size(),
	    n4 = nums4.size();
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			mp[nums1[i] + nums2[j]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < n3; i++) {
		for (int j = 0; j < n4; j++) {
			int x = -nums3[i] - nums4[j];
			ans += mp[x];
		}
	}
	return ans;
}