// 1751. Maximum Number of Events That Can Be Attended II
/*

You are given an array of events where events[i] = [startDayi, endDayi, valuei].
The ith event starts at startDayi and ends at endDayi, and if you attend this event, 
you will receive a value of valuei. 
You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. 
If you choose to attend an event, you must attend the entire event. 
Note that the end day is inclusive: that is, 
you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

 
*/

class Solution {
public:
int binarysearch(vector<vector<int>>& events, int prev, int n) {
    int lo = prev, hi = n - 1;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (events[mid][0] > events[prev][1])
            hi = mid;
        else
            lo = mid;
    }
    if (events[lo][0] > events[prev][1]) return lo;
    if (events[hi][0] > events[prev][1]) return hi;
    return n; 
}

int fn(vector<vector<int>>& events, int prev, int k, int ct, int n, vector<vector<int>>& dp) {
    if (prev >= n || ct >= k) return 0;
    if (dp[prev][ct] != -1) return dp[prev][ct];

    int nextind = binarysearch(events, prev, n);
    int value = events[prev][2];
    int take = value + fn(events, nextind, k, ct + 1, n, dp);
    int skip = fn(events, prev + 1, k, ct, n, dp);
    return dp[prev][ct] = max(take, skip);
}

int maxValue(vector<vector<int>>& events, int k) {
    int n = events.size();
    sort(events.begin(), events.end());
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return fn(events, 0, k, 0, n, dp);
}

};

// 2054. Two Best Non-Overlapping Events only change is k=2 and there k is varaible


class Solution {
public:
int binarysearch(vector<vector<int>>& events, int prev, int n) {
    int lo = prev, hi = n - 1;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (events[mid][0] > events[prev][1])
            hi = mid;
        else
            lo = mid;
    }
    if (events[lo][0] > events[prev][1]) return lo;
    if (events[hi][0] > events[prev][1]) return hi;
    return n; 
}

int fn(vector<vector<int>>& events, int prev, int k, int ct, int n, vector<vector<int>>& dp) {
    if (prev >= n || ct >= k) return 0;
    if (dp[prev][ct] != -1) return dp[prev][ct];

    int nextind = binarysearch(events, prev, n);
    int value = events[prev][2];
    int take = value + fn(events, nextind, k, ct + 1, n, dp);
    int skip = fn(events, prev + 1, k, ct, n, dp);
    return dp[prev][ct] = max(take, skip);
}
int maxTwoEvents(vector<vector<int>>& events) {
    int n = events.size();
    sort(events.begin(), events.end());
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    return fn(events, 0, 2, 0, n, dp);
    }
};