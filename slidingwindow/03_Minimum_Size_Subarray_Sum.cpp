/*

1.)Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution,
try coding another solution of which the time complexity is O(n log(n)).


*/

// key point here all the element are positive so binary search can be applied

// a) sliding window solution

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& arr) {
		int i = 0;
		int j = 0;
		int n = arr.size();
		int ans = n + 1;
		int sum = 0;
		while (j < n) {
			if (sum + arr[j] < target) {
				sum = sum + arr[j];
				j++;
			} else {
				ans = min(ans, j - i + 1);
				sum = sum - arr[i];
				i++;
			}
			cout << sum << " ";
		}
		if (ans == n + 1)return 0;
		return ans;
	}
};

// key point here all the element are positive so binary search can be applied
// binary search solution
class Solution {
public:
	bool ispossible(int mid, vector<int>& nums, int target) {
		int sum = 0;
		int n = nums.size();
		for (int i = 0; i < mid; ++i) {
			sum += nums[i];
		}
		if (sum >= target)
			return true;
		int i = 0;
		int j = mid;
		while (j < n) {
			sum = sum - nums[i];
			i++;
			sum = sum + nums[j];
			j++;
			if (sum >= target)
				return true;
		}
		return false;
	}

	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		int hi = n + 1;
		int lo = 0;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			bool flag = ispossible(mid, nums, target);
			if (flag) {
				hi = mid;
			} else
				lo = mid;
		}
		if (hi == n + 1)
			return 0;
		return hi;
	}
};

// 2)
/*862. Shortest Subarray with Sum at Least K
Given an integer array nums and an integer k
return the length of the shortest non-empty subarray of nums with a sum of at least k.
If there is no such subarray, return -1.
A subarray is a contiguous part of an array.
*/

// here we will use monotonic deque which will maintain the increasing order

class Solution {
public:
	int shortestSubarray(vector<int>& nums, int k) {
		int n = nums.size();
		vector<long long> prefix(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			prefix[i] = prefix[i - 1] + nums[i - 1];
		}
		deque<long long> dq;
		long long ans = INT_MAX;
		for (int i = 0; i <= n; i++) {
// if total prefix sum is greater than required then we start popping element from front (step is like moving front pointer)
			while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) { //
				ans = min(ans, i - dq.front() + 0LL);
				dq.pop_front();
			}
// if curr index prefix sum lesser than the prefix sum at index back of deque so we will not enter it to maintain montonicity
			while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
				dq.pop_back();
			}
			dq.push_back(i);
		}
		if (ans == INT_MAX)return -1;
		return (int)ans;
	}
};