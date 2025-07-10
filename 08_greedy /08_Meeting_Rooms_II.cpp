// 08_Meeting_Rooms_II.cpp

// --------------greedy also 

/*
Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting 
and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.

Constraints:
1 ≤ start.size() ≤ 105
0 ≤ start[i] < end[i] ≤ 106

*/


class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)v.push_back({start[i],end[i]});
        sort(v.begin(),v.end());
        multiset<int>endtime;
        for(int i=0;i<n;i++){
            auto it = endtime.upper_bound(v[i].first);
            if(it!=endtime.begin()){
                --it;
                endtime.erase(it);
            }
            endtime.insert(v[i].second);
        }
        return endtime.size();
    }
};
