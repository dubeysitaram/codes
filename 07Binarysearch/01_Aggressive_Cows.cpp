/*
You are given an array with unique elements of stalls[],
which denote the position of a stall.
You are also given an integer k which denotes the number of aggressive cows.
Your task is to assign stalls to k cows such that
the minimum distance between any two of them is the maximum possible.

*/

class Solution {
public:
	bool ispossible(int mid, vector<int> &stalls, int k) {
		int ct = 1;
		int curr = stalls[0];
		int n = stalls.size();

		while (ct < k) {
			int ind = lower_bound(stalls.begin(), stalls.end(), curr + mid) - stalls.begin();
			if (ind == n) return false;
			curr = stalls[ind];
			ct++;
		}
		return true;
	}

	int aggressiveCows(vector<int> &stalls, int k) {
		sort(stalls.begin(), stalls.end());
		int lo = 0, hi = 1e9;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (ispossible(mid, stalls, k)) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		return lo;
	}
};
