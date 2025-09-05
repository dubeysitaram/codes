// 001_selection_sort.cpp


// find the minimum from the leftover array and place it at correct position(ith position)



class Solution {
public:

	void selectionSort(vector<int> &arr) {
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			int min_index = i;
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[min_index]) {
					min_index = j;
				}
			}
			swap(arr[i], arr[min_index]);
		}


	}
};