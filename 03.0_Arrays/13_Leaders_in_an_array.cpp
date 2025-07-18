/*
You are given an array arr of positive integers.
Your task is to find all the leaders in the array.
An element is considered a leader if it is greater than or equal to all elements to its right.
The rightmost element is always a leader.
*/



class Solution {
	// Function to find the leaders in the array.
public:
	vector<int> leaders(vector<int>& arr) {
		// Code here
		int n = arr.size();
		vector<int>ans;
		ans.push_back(arr[n - 1]);
		int currmax = arr[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i] >= currmax) {
				ans.push_back(arr[i]);
				currmax = max(currmax, arr[i]);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};