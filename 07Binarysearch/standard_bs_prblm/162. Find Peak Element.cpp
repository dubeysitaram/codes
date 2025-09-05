/*162. Find Peak Element.cpp
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.
In other words, an element is always considered to be strictly greater than a neighbor
that is outside the array.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return 0;
		if (nums[n - 1] > nums[n - 2])
			return n - 1;
		if (nums[0] > nums[1])
			return 0;

		int hi = n - 1;
		int lo = 0;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
				return mid;
			} else if (nums[mid] < nums[mid + 1])
				lo = mid;
			else
				hi = mid - 1;
		}
		return hi;
	}
};