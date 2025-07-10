/*
LEETCODE 56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int lo = intervals[0][0];
        int hi = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (hi >= intervals[i][0]) {
                if (hi > intervals[i][1])
                    continue;
                hi = intervals[i][1];
            } else {
                ans.push_back({lo, hi});
                lo = intervals[i][0];
                hi = intervals[i][1];
            }
        }
        ans.push_back({lo, hi});

        return ans;
    }
};

