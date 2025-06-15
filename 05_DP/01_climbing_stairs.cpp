/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Constraints:

1 <= n <= 45
*/

class Solution {
public:
    int k;
    int dp[47];

    int climb(int index) {
        if (index > k) {
            return 0;
        }
        if (index == k) {
            return 1;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        dp[index] = climb(index + 1) + climb(index + 2);
        return dp[index];
    }

    int climbStairs(int n) {
        k = n;
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return climb(0); // Start from the bottom (step 0)
    }
};