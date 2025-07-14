// 42. Trapping Rain Water

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.
*/

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		vector<int> prefix_left_max(n);
		vector<int> prefix_right_max(n);
		prefix_left_max[0] = height[0];
		for (int i = 1; i < n; ++i) {
			prefix_left_max[i] = max(prefix_left_max[i - 1], height[i]);
		}
		prefix_right_max[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			prefix_right_max[i] = max(prefix_right_max[i + 1], height[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = ans + max(min(prefix_left_max[i], prefix_right_max[i]) - height[i], 0);
		}
		return ans;
	}
};