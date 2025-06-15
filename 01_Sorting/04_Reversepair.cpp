/*
Given an integer array nums, return the number of reverse pairs in the array.
--> A reverse pair is a pair (i, j) where:
--->0 <= i < j < nums.length and
--->nums[i] > 2 * nums[j].

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/











// concept slightly varied from  the count inversion as here we have to count the arr[i]>2*arr[j]
// so we cannot directly right the inside the if condition inside the merge function as we did in count inversion

class Solution {
public:
	long long ans = 0;
	void countpairs(vector<pair<long long, long long>>& arrindex, long long lo, long long mid, long long hi) {
		long long i = lo;
		long long j = mid + 1;
		while (i <= mid) {
			while (j <= hi && arrindex[i].first > 2 * arrindex[j].first) {
				j++;
			}
			ans += j - (mid + 1);
			i++;
		}

	}

	void merge(vector<pair<long long, long long>>& arrindex, long long lo, long long mid, long long hi) {
		long long n = hi - lo + 1;
		vector<pair<long long, long long>> sortedarray(n);
		long long i = lo; // 0 se start nhi kr skte as on each level lo is not zero,
		long long j = mid + 1;
		long long k = 0;
		while (i <= mid && j <= hi) {
			if (arrindex[i].first <= arrindex[j].first) {
				sortedarray[k] = arrindex[i];
				i++;
				k++;
			} else {
				sortedarray[k] = arrindex[j];
				j++;
				k++;
			}
		}
		while (i <= mid) {
			sortedarray[k] = arrindex[i];
			i++;
			k++;
		}
		while (j <= hi) {
			sortedarray[k] = arrindex[j];
			j++;
			k++;
		}
		i = lo; // 0 se start nhi kr skte as on each level lo is not zero,
		k = 0;
		while (i <= hi) {
			arrindex[i] = sortedarray[k];
			i++;
			k++;
		}
	}

	void mergesort(vector<pair<long long, long long>>& arrindex, long long lo, long long hi) {
		if (lo >= hi)
			return;
		long long mid = lo + (hi - lo) / 2;
		mergesort(arrindex, lo, mid);
		mergesort(arrindex, mid + 1, hi);
		countpairs(arrindex, lo, mid, hi);
		merge(arrindex, lo, mid, hi);
	}

	int reversePairs(vector<int>& nums) {
		long long n = nums.size();
		vector<pair<long long, long long>> numindex(n);
		for (long long i = 0; i < n; i++) {
			numindex[i] = {nums[i], i};
		}
		mergesort(numindex, 0, n - 1);
		return ans;
	}
};