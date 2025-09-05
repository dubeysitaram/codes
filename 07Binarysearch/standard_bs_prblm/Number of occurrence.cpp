/* Number of occurrence.cpp
Given a sorted array,
arr[] and a number target, you need to find the number of occurrences of target in arr[].
*/

int countFreq(vector<int>& arr, int target) {
	auto it1 = upper_bound(arr.begin(), arr.end(), target);
	auto it2 = lower_bound(arr.begin(), arr.end(), target);
	if (*it2 != target)return 0;
	return it1 - it2;
}