/* 4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/
// merege sort based solution
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int n = n1 + n2;
		vector<int> final(n);
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < n1 && j < n2) {
			if (nums1[i] <= nums2[j]) {
				final[k] = nums1[i];
				i++;
				k++;
			} else {
				final[k] = nums2[j];
				j++;
				k++;
			}
		}
		while (i < n1) {
			final[k] = nums1[i];
			i++; k++;
		}
		while (j < n2) {
			final[k] = nums2[j];
			j++; k++;
		}
		if (n % 2) {
			return final[n / 2];
		}
		return 0.5 * final[n / 2] + 0.5 * final[n / 2 - 1];
	}
};

// without extra space for the third array


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int n = n1 + n2;
		int i = 0;
		int j = 0;
		int el1, el2;
		int ct = 0;
		while (i < n1 && j < n2) {
			if (nums1[i] <= nums2[j]) {
				if (ct == n / 2) {
					el2 = nums1[i];
				}
				if (ct == n / 2 - 1) {
					el1 = nums1[i];
				}
				ct++;
				i++;

			} else {
				if (ct == n / 2) {
					el2 = nums2[j];
				}
				if (ct == n / 2 - 1) {
					el1 = nums2[j];
				}
				ct++;
				j++;
			}
		}
		while (i < n1) {
			if (ct == n / 2) {
				el2 = nums1[i];
			}
			if (ct == n / 2 - 1) {
				el1 = nums1[i];
			}
			ct++;
			i++;
		}
		while (j < n2) {
			if (ct == n / 2) {
				el2 = nums2[j];
			}
			if (ct == n / 2 - 1) {
				el1 = nums2[j];
			}
			j++;
			ct++;
		}
		if (n % 2) {
			return el2;
		}
		return 0.5 * el1 + 0.5 * el2;
	}
};