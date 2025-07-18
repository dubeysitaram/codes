/*https://www.geeksforgeeks.org/problems/count-quadruplets-with-given-sum/0


Given an array arr[] and an integer target,
you need to find and return the count of quadruplets
such that the index of each element of the quadruplet is unique and
the sum of the elements is equal to target.

Constraints:
1 <= arr.length <= 103
-105 <=arr[i]<= 105
-105 <=target<= 105



Input: arr[] = [1, 5, 3, 1, 2, 10], target = 20
Output: 1
Explanation:
Only quadruplet satisfying the condition is arr[1] + arr[2] + arr[4] + arr[5] = 5 + 3 + 2 + 10 = 20.
Hence, the answer is 1.
*/

//---------------------------------------------------------------------------------------------------------------------------


// this will give tle beacuse we are using the 3 loops
// here we are using the concept that the
// we are fizing the value of i and j and then we iterate over k =j+1
// in search of the reqlast_element = target - nums[i] -nums[j]-nums[k];
// we search for the last req element in between of the j and k
// if req element is present we add frequency that

class Solution {
public:
	int countSum(vector<int>& nums, int target) {
		int ans = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				unordered_map<int, int>mp;
				for (int k = j + 1; k < n; k++) {
					int reqlast = target - nums[i] - nums[j] - nums[k];
					if (mp.find(reqlast) != mp.end()) {
						ans += mp[reqlast];
					}
					mp[nums[k]]++;
				}
			}
		}
		return ans;
	}
};



// optimal
// we do not require the value of the lastelement rather we want only the number of ways
// so we can work without using the third loop
// previously we were storing the freq of nums[k]
// this time we will store the freq of the sum of n



// Function to return the number of quadruplets having the given target sum
int countSum(vector<int>& nums, int target) {
	int ans = 0;
	int n = nums.size();
	// mp will Store the frequency of sum of first two elements
	unordered_map<int, int>mp;

	// Traverse from 0 to n-1, where arr[i] is the 3rd element
	for (int i = 0; i < n; i++) {

		// All possible 4th elements
		for (int j = i + 1; j < n; j++) {

			// Sum of last two elements
			int x = nums[i] + nums[j];
			int req = target - x;

			// Check for valid sum of the first two elements
			if (mp.find(req) != mp.end())ans += mp[req];
		}
		// Store frequency of all possible sums of first two elements
		for (int j = 0; j < i; j++) {
			mp[nums[i] + nums[j]]++;
		}
	}
	return ans;
}
