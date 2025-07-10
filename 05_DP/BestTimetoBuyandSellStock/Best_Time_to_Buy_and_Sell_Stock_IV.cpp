// Best_Time_to_Buy_and_Sell_Stock_IV.cpp

/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, 
and an integer k.

Find the maximum profit you can achieve. 
You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).



*/

class Solution {
public:
    int maxProfit(int x, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(x + 1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                for (int k = 0; k < x; k++) {
                    if (j == 0)
                        dp[i][j][k] =max(dp[i + 1][j][k], -prices[i] + dp[i + 1][!j][k]);
                    else {
                        dp[i][j][k] = max(dp[i + 1][j][k],prices[i] + dp[i + 1][!j][k + 1]);
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};