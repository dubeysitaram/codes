/*
898. Bitwise ORs of Subarrays

Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray.
The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:


	int calculate(int i, int j, vector<int>& arr) {
		if (j >= arr.size()) return 0;
		int ans = 0;
		for (int k = i; k <= j; k++) {
			ans |= arr[k];
		}
		return ans;
	}

	int subarrayBitwiseORs(vector<int>& arr) {
		int n = arr.size();
		unordered_map<int, int> mp;
		for (int win_size = 1; win_size <= 38; win_size++) {
			for (int i = 0; i + win_size - 1 < n; i++) {
				int val = calculate(i, i + win_size - 1, arr);
				mp[val]++;
			}
		}
		return mp.size();
	}

};