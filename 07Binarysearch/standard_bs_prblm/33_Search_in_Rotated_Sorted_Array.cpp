/* 33_Search_in_Rotated_Sorted_Array.cpp
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k
(1 <= k < nums.length) such that the resulting array is
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

// yaha hame mid ko lo se compare krke dekhenge konsa part sorted hai
// agr mid ki value lo se bdi hai to left wala part sorted hai
// else right wala part sorted hai
// ab har sorted part mai check krna hai kya target reside krr skta hai kya
// ussi hisab se mid ko kis taraf move krna hai dekh lena

class Solution {
public:
	int search(vector<int>& arr, int target) {
		int n = arr.size();
		if (arr[0] == target)
			return 0;
		if (arr[n - 1] == target)
			return n - 1;
		int lo = 0;
		int hi = n - 1;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			if (arr[mid] == target)
				return mid;
			if (arr[lo] <= arr[mid]) {
				if (arr[lo] <= target && arr[mid] > target) {
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			} else {
				if (arr[hi] >= target && arr[mid] < target) {
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
		}
		if (arr[lo] == target)
			return lo;
		if (arr[hi] == target)
			return hi;
		return -1;
	}
};