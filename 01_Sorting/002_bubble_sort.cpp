// 002_bubble_sort.cpp
// adjacent swapping is the key here
// we will swap the current element with the next if it is unsorted

class Solution {
public:
	void bubbleSort(vector<int>& arr) {
		// code here
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1])swap(arr[j], arr[j + 1]);
			}
		}
	}
};