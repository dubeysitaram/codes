

/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

*/




// key idea  -->  O(2*N) = O(N)
// max element that cannot be positive it length of the array +1

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i <= n; i++) {
			nums.push_back(0);
		}
		// inserting n+1 zeros because all the alement form 1 to n can be present so our answer will become n+1
		for (int i = 0; i < n; i++) {
			if (nums[i] >= 0 && nums[i] <= n)
				nums[n + nums[i]]++;
		}
		for (auto it : nums)
			cout << it << " ";
		for (int i = n + 1; i <= 2 * n; i++) {
			if (nums[i] == 0)
				return i - n;
		}
		return n + 1;
	}
};