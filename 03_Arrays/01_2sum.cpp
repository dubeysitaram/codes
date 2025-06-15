/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



*/

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;
        vector<pair<int, int>> vp;
        for (int i = 0; i < arr.size(); i++) {
            vp.push_back({arr[i], i});
        }
        sort(vp.begin(), vp.end());
        while (lo < hi) {
            if (vp[lo].first + vp[hi].first == target) {
                return {vp[lo].second + vp[hi].second};
            } else if (vp[lo].first + vp[hi].first < target) {
                lo++;
            } else {
                hi--;
            }
        }
        return {};
    }
};
