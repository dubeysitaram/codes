/*
You are given an array of integers nums,

there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/


class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		multiset<int> s;
		vector<int>ans;
		int n = nums.size();
		for (int i = 0; i < k; i++) {
			s.insert(nums[i]);
		}
		ans.push_back(*s.rbegin());
		for (int i = k; i < n; i++) {
			s.erase(s.find(nums[i - k]));
			s.insert(nums[i]);
			ans.push_back(*s.rbegin());
		}
		return ans;
	}
};