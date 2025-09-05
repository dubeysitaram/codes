// 57. Insert Interval
/*
You are given an array of non-overlapping intervals intervals where intervals[i] =
[starti, endi] represent the start and the end of the ith interval and
intervals is sorted in ascending order by starting.
You are also given an interval newInterval = [start, end] that represents the start
and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by
starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.
*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            int curr_upperlimit = ans[ans.size() - 1][1];
            if (curr_upperlimit >= intervals[i][0]) {
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }

        }
        return ans;
    }
};


// simply call the code of merger interval on the interval vector after inserting the inetrval to be inserted

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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
