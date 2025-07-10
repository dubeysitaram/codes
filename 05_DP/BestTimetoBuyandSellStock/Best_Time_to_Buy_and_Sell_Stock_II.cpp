// LC122  Best_Time_to_Buy_and_Sell_Stock_II.cpp


/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 */



class Solution {
public:
    int fn(int i, int prev, vector<int>& prices, int n,
           vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }
        if (prev != 0 && i == n - 1) {
            return prices[n - 1];
        }
        if (dp[i][prev] != -1)
            return dp[i][prev];
        int ans = 0;

        if (prev == 0) {
            int buy = -prices[i] + fn(i + 1, 1, prices, n, dp);
            int skip = fn(i + 1, 0, prices, n, dp);
            ans = max({ans, buy, skip});

        } else {
            int hold = fn(i + 1, 1, prices, n, dp);
            int sell = prices[i] + fn(i + 1, 0, prices, n, dp);
            ans = max({ans, sell, hold});
        }
        return dp[i][prev] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fn(0, 0, prices, n, dp);
    }
};