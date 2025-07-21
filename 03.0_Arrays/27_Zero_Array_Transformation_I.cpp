// 3355_Zero_Array_Transformation_I.cpp
/*
You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially,
otherwise return false.

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length
*/

class Solution {
public:
	bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		int q = queries.size();
		vector<int> diffarray(n + 1, 0);
		for (int i = 0; i < q; i++) {
			int l = queries[i][0];
			int r = queries[i][1];
			diffarray[l]++;
			if (r + 1 < n) {
				diffarray[r + 1]--;
			}
		}
		for (int i = 1; i < n; i++) {
			diffarray[i] += diffarray[i - 1];
		}
		for (int i = 0; i < n; i++) {
			if (diffarray[i] < nums[i])
				return false;
		}
		return true;
	}
};