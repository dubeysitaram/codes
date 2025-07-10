// lc123 Best_Time_to_Buy_and_Sell_Stock_III.cpp

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously
 (i.e., you must sell the stock before you buy again).

*/

//MEMOIZATION
class Solution {
public:
    int fn(int ind , int prev,int ct,vector<int>& prices,int n, vector<vector<vector<int>>>&dp){
        if(ind>=n)return 0;
        if(ct>=2)return 0;
        if(dp[ind][prev][ct]!=-1)return dp[ind][prev][ct];
        int ans=0;
        if(prev==0 && ct<2){
            int buy = -prices[ind]+fn(ind+1,1,ct,prices,n,dp);
            int skip = fn(ind+1,0,ct,prices,n,dp);
            ans=max(buy,skip);
        }else{
            int sell = +prices[ind]+fn(ind+1,0,ct+1,prices,n,dp);
            int hold = fn(ind+1,1,ct,prices,n,dp);
            ans=max(sell,hold);
        }
        return dp[ind][prev][ct]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return fn(0,0,0,prices,n,dp);
    }
};


// TABULATION

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                for(int k=0;k<2;k++){

                if(j==0)dp[i][j][k] = max(dp[i+1][j][k],-prices[i]+dp[i+1][!j][k]);
                else {
                    dp[i][j][k] = max(dp[i+1][j][k],prices[i]+dp[i+1][!j][k+1]);
                } 
                }
            }
        }
        return dp[0][0][0];
    }
};