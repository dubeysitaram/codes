/*
Given an array of integers nums and an integer k,
return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		map<int, int> mp;
		int sum = 0;
		int ans = 0;
		mp[0]++;
		for (int i = 0; i < n; i++) {
			sum += nums[i];

			if (mp.find(sum - k) != mp.end())
				ans += mp[sum - k];
			mp[sum]++;
		}

		return ans;
	}
};

/*
713. Subarray Product Less Than K

Given an array of integers nums and an integer k,
return the number of contiguous subarrays
where the product of all the elements in the subarray is strictly less than k.

*/
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k == 0 || k == 1)return 0;
		int i = 0;
		int j = 0;
		int prod = 1;
		int ct = 0;
		int n = nums.size();
		while (j < n) {
			prod *= nums[j];
			if (prod >= k) {
				while (prod >= k) {
					prod /= nums[i];
					i++;
				}
				if (prod == 1) {j++; continue;}
			}
			if (prod == 0) break;
			int add = j - i + 1;
			ct += add;
			j++;
		}
		return ct;
	}
};




/*

variation of kadane

152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

*/

class Solution {
public:

	int maxProduct(vector<int>& nums) {
		double prod = INT_MIN; double temp = 1;
		for (int i = 0; i < nums.size(); i++) {
			temp *= nums[i];
			prod = max(prod, temp);
			if (temp == 0)temp = 1;
		}
		temp = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			temp *= nums[i];
			prod = max(prod, temp);
			if (temp == 0)temp = 1;
		}
		return int(prod);
	}
};





// 1248. Count Number of Nice Subarrays

/*

Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

*/

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














// 2302. Count Subarrays With Score Less Than K