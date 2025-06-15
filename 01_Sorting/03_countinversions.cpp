/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104


*/

// key idea use the merge sort

class Solution {
public:
	int ans = 0;
	void merge(vector<pair<int, int>>&arrindex, int lo, int mid, int hi) {
		int n = hi - lo + 1;
		vector<pair<int, int>>sortedarray(n);
		int i = lo;//// 0 se start nhi kr skte as on each level lo is not zero,
		int	j = mid + 1;
		int k = 0;
		while (i <= mid && j <= hi) {
			if (arrindex[i].first <= arrindex[j].first) {
				sortedarray[k] = arrindex[i];
				i++; k++;
			} else {
				sortedarray[k] = arrindex[j];
				ans += (mid - i + 1);
				j++; k++;
			}
		}
		while (i <= mid) {
			sortedarray[k] = arrindex[i];
			i++; k++;
		}
		while (j <= hi) {
			sortedarray[k] = arrindex[j];
			j++; k++;
		}
		i = lo; // 0 se start nhi kr skte as on each level lo is not zero,
		k = 0;
		while (i <= hi) {
			arrindex[i] = sortedarray[k];
			i++; k++;
		}
	}


	void mergesort(vector<pair<int, int>>&arrindex, int lo, int hi) {
		if (lo >= hi)return;
		int mid = lo + (hi - lo) / 2;
		mergesort(arrindex, lo, mid);
		mergesort(arrindex, mid + 1, hi);
		merge(arrindex, lo, mid, hi);
	}




	int inversionCount(vector<int> &arr) {
		int n = arr.size();
		vector<pair<int, int>> numindex(n);
		for (int i = 0; i < n; i++) {
			numindex[i] = {arr[i], i};
		}
		mergesort(numindex, 0, n - 1);
		return ans;
	}

};