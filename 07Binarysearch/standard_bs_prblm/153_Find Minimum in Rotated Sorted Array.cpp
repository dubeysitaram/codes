/*
153_Find Minimum in Rotated Sorted Array.cpp

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

*/

// ek baar dry run krke dekh le 4 5 6 7 1 2 3 pe main to yhi hai ki mid ki
// value n-1th index se compare krke dek lena

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int hi = n - 1; int lo = 0;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (nums[mid] > nums[n - 1]) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		return min(nums[lo], nums[hi]);
	}
};