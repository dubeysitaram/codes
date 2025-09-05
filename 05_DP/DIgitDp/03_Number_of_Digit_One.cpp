// 233. Number of Digit One
/*
Given an integer n, count the total number of digit 1 appearing
in all non-negative integers less than or equal to n.



Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0


Constraints:

0 <= n <= 109


*/

class Solution {
public:
	typedef long long ll;
	int dp[20][2][180];
	int fn(int pos, int flag, int ct, int sizelimit, vector<int>& digit_at_eachpos) {
		if (pos == sizelimit) {
			return ct;
		}
		if (dp[pos][flag][ct] != -1) {
			return dp[pos][flag][ct];
		}

		int res = 0;

		if (flag == 1) {
			for (int i = 0; i <= digit_at_eachpos[pos]; ++i) {
				if (i == digit_at_eachpos[pos]) {
					if (i == 1)
						res += fn(pos + 1, 1, ct + 1, sizelimit, digit_at_eachpos);
					else
						res += fn(pos + 1, 1, ct, sizelimit, digit_at_eachpos);
				}
				if (i < digit_at_eachpos[pos]) {
					if (i == 1)
						res += fn(pos + 1, 0, ct + 1, sizelimit, digit_at_eachpos);
					else
						res += fn(pos + 1, 0, ct, sizelimit, digit_at_eachpos);
				}
			}
		}

		if (flag == 0) {
			for (int i = 0; i <= 9; ++i) {
				if (i == 1)
					res += fn(pos + 1, 0, ct + 1, sizelimit, digit_at_eachpos);
				else
					res += fn(pos + 1, 0, ct, sizelimit, digit_at_eachpos);
			}
		}

		return dp[pos][flag][ct] = res;
	}
	int compute(ll x) {
		if (x < 0)
			return 0;

		vector<int> digit_at_eachpos;
		while (x > 0) {
			digit_at_eachpos.push_back(x % 10);
			x /= 10;
		}
		reverse(digit_at_eachpos.begin(), digit_at_eachpos.end());

		int sizelimit = digit_at_eachpos.size();
		memset(dp, -1, sizeof(dp));

		return fn(0, 1, 0, sizelimit, digit_at_eachpos);
	}
	int countDigitOne(int n) {
		return compute(n);
	}
};



