// 1235. Maximum Profit in Job Scheduling
/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], 
obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, 
return the maximum profit you can take such that 
there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
*/



class Solution {
public:
    int binarysearch(vector<vector<int>>&jobs,int prev,int n){
        int lo =  prev,hi = n-1;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(jobs[mid][0]>=jobs[prev][1]){
                hi=mid;
            }else{
                lo=mid;
            }
        }
        if(jobs[lo][0]>=jobs[prev][1])return lo;
        if(jobs[hi][0]>=jobs[prev][1])return hi;
        return n;

    }
    int fn(vector<vector<int>>&jobs,int prev,int n,vector<int>&dp){
        if(prev>=n)return 0;
        if(dp[prev]!=-1)return dp[prev];
        int ans = 0;
        int nextind = binarysearch(jobs,prev,n);
        int profit = jobs[prev][2];
        int take =  profit + fn(jobs,nextind,n,dp);
        int skip = fn(jobs,prev+1,n,dp);
        ans = max(take,skip);
        return dp[prev]=ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        vector<int>dp(n,-1);
        sort(jobs.begin(),jobs.end());
        return fn(jobs,0,n,dp);

    }
};