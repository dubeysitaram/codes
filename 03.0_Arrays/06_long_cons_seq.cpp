/*
https://leetcode.com/problems/longest-consecutive-sequence/description/

Given an unsorted array of integers nums,
return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/


int longestConsecutive(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)return 0;
	unordered_set<int> s(nums.begin(), nums.end());
	int ans = 1;

	for (int x : s) {
		// if smaller then curr element is present then that smaller elemnt will include curr elem when his chance will come
		// so continue if 1 smaller is present
		if (s.find(x - 1) != s.end())
			continue;

		int currval = x;
		int currans = 1;
		while (s.find(currval + 1) != s.end()) {
			currans++;
			currval++;
		}
		ans = max(ans, currans);
	}
	return ans;
}