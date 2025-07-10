// 1353. Maximum Number of Events That Can Be Attended

/*

You are given an array of events where events[i] = [startDayi, endDayi]. 
Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. 
You can only attend one event at any time d.

 Return the maximum number of events you can attend.
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        int day = events[0][0];
        int ct=0;
        multiset<int> ms;
        int i=0;
        while (i < n || !ms.empty()) {
            while (i<n && events[i][0] == day) {
                ms.insert(events[i][1]);
                i++;
            }
            if(!ms.empty()){
                ms.erase(ms.begin());
                ct++;    
            }
            day++;
            while(!ms.empty() && *ms.begin()<day)ms.erase(ms.begin());
            if(i<n && ms.empty()) day = events[i][0];
        }
        return ct;
    }
};


