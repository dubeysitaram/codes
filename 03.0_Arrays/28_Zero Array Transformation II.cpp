// 3356. Zero Array Transformation II
/*

You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence,
nums becomes a Zero Array. If no such k exists, return -1.

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 5 * 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5

*/
// simple binary search on answer  question

class Solution {
public:
	bool ispossible(int mid, vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		int q = queries.size();
		vector<int> diffarray(n + 1, 0);
		for (int i = 0; i <= mid; i++) {
			int l = queries[i][0];
			int r = queries[i][1];
			int val = queries[i][2];
			diffarray[l] += val;
			if (r + 1 < n) {
				diffarray[r + 1] -= val;
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
	int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int lo = -1, hi = queries.size() - 1;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (ispossible(mid, nums, queries)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		if (!ispossible(hi, nums, queries))return -1;
		return (ispossible(lo, nums, queries)) ? lo + 1 : hi + 1;
	}
};