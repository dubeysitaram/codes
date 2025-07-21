// 3489. Zero Array Transformation IV

/*
You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Select a subset of indices in the range [li, ri] from nums.
Decrement the value at each selected index by exactly vali.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence,
 nums becomes a Zero Array. If no such k exists, return -1.


*/
// simple binary search + dp (kanpsack wali )

class Solution {
public:
	int dp[1001][1001];
	bool fn2(int target, vector<vector<int>>& queries, int ind, int i, int mid) {
		if (target == 0)
			return true;
		if (i > mid || target < 0)
			return false;
		if (dp[target][i] != -1)return dp[target][i];
		bool ans = false;
		int l = queries[i][0];
		int r = queries[i][1];
		int val = queries[i][2];
		if (ind >= l && ind <= r) {
			ans |= fn2(target - val, queries, ind, i + 1, mid);
		}
		ans |= fn2(target, queries, ind, i + 1, mid);
		return dp[target][i] = ans;
	}

	bool fn(int mid, vector<int>& nums, vector<vector<int>>& queries) {

		for (int i = 0; i < nums.size(); i++) {

			memset(dp, -1, sizeof(dp));
			if (!fn2(nums[i], queries, i, 0, mid)) {
				return false;
			}
		}
		return true;
	}

	int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int q = queries.size();
		if (fn(-1, nums, queries))return 0;
		int lo = -1, hi = q;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (fn(mid, nums, queries))
				hi = mid;
			else
				lo = mid;
		}
		cout << lo << endl;
		if (hi == q)
			return -1;
		return hi + 1;
	}
};
