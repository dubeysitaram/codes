//LC 1248 Count Number of Nice Subarrays
/*
Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
*/


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int oddct = 0;
        mp[0]++;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2)
                oddct++;

            if (mp.find(oddct - k) != mp.end())
                ans += mp[oddct - k];
            mp[oddct]++;
        }
        return ans;
    }
};