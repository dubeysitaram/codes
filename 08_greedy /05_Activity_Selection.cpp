/*
leetcode 435.Non-overlapping Intervals or 
GFG --> Activity Selection or 
GFG --> Maximal Disjoint Intervals both on  gfg
leetcode 452. Minimum Number of Arrows to Burst Balloons

You are given a set of activities, each with a start time and a finish time, 
represented by the arrays start[] and finish[], respectively. 
A single person can perform only one activity at a time, meaning no two activities can overlap. 
Your task is to determine the maximum number of activities that a person can complete in a day.
*/


class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = finish.size();
        vector<vector<int>>pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({start[i],finish[i]});
        }
        sort(pairs.begin(),pairs.end(),[&](vector<int>p1,vector<int>p2){
            return p1[1]<p2[1];
        });
        int curr = pairs[0][1];
        int ans=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>curr){
                ans++;
                curr= pairs[i][1];
            }
        }
        return ans;
    }
};


// 3169. Count Days Without Meetings
/*
You are given a positive integer days representing the total number of days an employee is available
 for work (starting from day 1).
 You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents 
the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.
*/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
       
        int n = meetings.size();
        int x = meetings[0][1];
        days = days - (meetings[0][1] - meetings[0][0] + 1);
        for (int i = 1; i < n; i++) {
            if (meetings[i][0] <= x && meetings[i][1]>x ) {
                days = days - (meetings[i][1] - x);
                x = meetings[i][1];
            } else if(meetings[i][0]>x) {
                days = days - (meetings[i][1] - meetings[i][0] + 1);
                x = meetings[i][1];
            }
        }
        return days;
    }
};