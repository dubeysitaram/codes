/*
81. Search in Rotated Sorted Array II.cpp
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target,
return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
*/

class Solution {
public:
	bool search(vector<int>& arr, int target) {
		int hi = arr.size() - 1;
		int lo = 0;

		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (arr[mid] == target) {
				return 1;
			}
			if (arr[mid] == arr[lo] && arr[mid] == arr[hi]) {
				lo++; hi--; // if test case is like 1 0 1 1 1 1 then we cannot predict which part is sorted
				// so increase lo and decrese hi till one of them is not equal to mid
			}
			else if (arr[lo] <= arr[mid]) { // left half is sorted
				if (target >= arr[lo] && target < arr[mid]) { // half is sorted so can predict elem
					// is there/not there
					hi = mid - 1;
				} else
					lo = mid + 1;
			} else {
				if (target > arr[mid] && target <= arr[hi]) {
					lo = mid + 1;
				} else
					hi = mid - 1;
			}
		}
		if (arr[lo] == target)
			return 1;
		if (arr[hi] == target)
			return 1;

		return 0;
	}
};