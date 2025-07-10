// Best_Time_to_Buy_and_Sell_Stock_VI_Transaction_Fee.cpp
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, 
and an integer fee representing a transaction fee.

Find the maximum profit you can achieve.
You may complete as many transactions as you like, 
but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {

                if (j == 0)
                    dp[i][j] = max(dp[i + 1][j], -prices[i] + dp[i + 1][!j]);
                else {
                    dp[i][j] =
                        max(prices[i] - fee + dp[i + 1][!j], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
