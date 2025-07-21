/*
1589. Maximum Sum Obtained of Any Permutation

We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi].
The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi].
Both starti and endi are 0-indexed.

Return the maximum total sum of all requests among all permutations of nums.

Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
	const int MOD = 1e9 + 7;
	int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
		long long n = nums.size();
		long long m = requests.size();
		vector<long long> v(n);
		for (long long i = 0; i < m; i++) {
			long long l = requests[i][0];
			long long r = requests[i][1];
			v[l]++;
			if (r + 1 < n)
				v[r + 1]--;
		}
		for (long long i = 1; i < n; i++) {
			v[i] += v[i - 1];
		}
		sort(v.rbegin(), v.rend());
		sort(nums.rbegin(), nums.rend());
		long long sum = 0;
		for (long long i = 0; i < n; i++) {
			sum = (sum + (nums[i] * v[i]) % MOD) % MOD;
		}
		return sum;
	}
};