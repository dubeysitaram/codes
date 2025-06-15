/*Given an integer array nums, return an integer array counts
where counts[i] is the number of smaller elements to the right of nums[i].

Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

// concept we will use the merge sort

// in which we will count number of the inversion or swap we have to make
// that are only our smaller element present at right


//  after mergersort() function calls we will get two sorted arrays arr1  and arr2  which we have to merge
//  if an elemnt in arr2 is req to swapped into arr1 means it is smaller the arr1[i]
// means it will be smaller than all the element present in arr1 from  i to mid


void merge(vector<pair<int, int>>& numindex, int lo, int mid, int hi, vector<int>& ans) {
	vector<pair<int, int>> sortedarray(hi - lo + 1);
	int i = lo; int j = mid + 1;
	int k = 0;
	int smalleronright = 0;
	while (i <= mid && j <= hi) {
		if (numindex[i].first <= numindex[j].first) {
			ans[numindex[i].second] += smalleronright;
			sortedarray[k] = numindex[i];
			i++;
			k++;
		} else {
			smalleronright++;
			sortedarray[k] = numindex[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		ans[numindex[i].second] += smalleronright;
		sortedarray[k] = numindex[i];
		i++;
		k++;
	}
	while (j <= hi) {
		sortedarray[k] = numindex[j];
		j++;
		k++;
	}
	i = lo; // 0 se start nhi kr skte as on each level lo is not zero
	k = 0;
	while (i <= hi) {
		numindex[i] = sortedarray[k];
		i++; k++;
	}
}

void mergesort(vector<pair<int, int>>& numindex, int lo, int hi, vector<int>& ans) {
	if (lo >= hi)return;
	int mid = lo + (hi - lo) / 2;
	mergesort(numindex, lo, mid, ans);
	mergesort(numindex , mid + 1, hi, ans);
	merge(numindex, lo, mid, hi, ans);
}

vector<int> countSmaller(vector<int>& nums) {
	int n = nums.size();
	vector<pair<int, int>> numindex(n);
	for (int i = 0; i < n; i++) {
		numindex[i] = {nums[i], i};
	}
	vector<int> ans(n, 0);
	mergesort(numindex, 0, n - 1, ans);
	return ans;
}