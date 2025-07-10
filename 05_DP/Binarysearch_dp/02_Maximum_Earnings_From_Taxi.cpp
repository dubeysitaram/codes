// 2008. Maximum Earnings From Taxi
/*

There are n points on a road you are driving your taxi on. 
The n points on the road are labeled from 1 to n in the direction you are going, 
and you want to drive from point 1 to point n to make money by picking up passengers. 
You cannot change the direction of the taxi.

The passengers are represented by a 0-indexed 2D integer array rides, 
where rides[i] = [starti, endi, tipi] 
denotes the ith passenger requesting a ride from point starti to point endi 
who is willing to give a tipi dollar tip.

For each passenger i you pick up, you earn endi - starti + tipi dollars. 
You may only drive at most one passenger at a time.

Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.

Note: You may drop off a passenger and pick up a different passenger at the same point.



*/


class Solution {
public:
long long binarysearch(vector<vector<int>>& rides, long long prev, long long sz) {
    long long lo = prev, hi = sz - 1;
    while (hi - lo > 1) {
        long long mid = (lo + hi) / 2;
        if (rides[mid][0] >= rides[prev][1])
            hi = mid;
        else
            lo = mid;
    }

    if (rides[lo][0] >= rides[prev][1]) return lo;
    if (rides[hi][0] >= rides[prev][1]) return hi;
    return sz; 
}


long long fn(long long sz, vector<vector<int>>& rides, int prev, vector<long long>& dp) {
    if (prev >= sz) return 0;
    if (dp[prev] != -1) return dp[prev];
    long long ans = 0;
    long long nextidx = binarysearch(rides, prev, sz);
    long long earning =rides[prev][1] - rides[prev][0] + rides[prev][2];
    long long take = earning+fn(sz, rides, nextidx, dp);
    long long skip = fn(sz, rides, prev + 1, dp);
    ans = max(take,skip);
    return dp[prev] = ans;
}

long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());
    int sz = rides.size();
    vector<long long> dp(sz, -1);
    return fn(sz, rides, 0, dp);
}

};