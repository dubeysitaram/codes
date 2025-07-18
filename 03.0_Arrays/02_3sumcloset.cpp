/*

16. 3Sum Closest


Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.


*/



class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int fsum = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            int x = nums[j]+nums[k];
            int req = target - nums[i];
            if (abs((target -nums[i]-nums[j]-nums[k])) < abs(target-fsum)) {
                fsum = nums[i]+nums[j]+nums[k];
            }
            if (x < req) {
                j++;
            } else if (x > req) {
                k--;
            } else {
                return target;
            }
        }
    }
    return fsum;
}

};