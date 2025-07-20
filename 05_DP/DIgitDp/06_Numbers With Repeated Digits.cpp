//1012. Numbers With Repeated Digits

/*
Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
*/

// using previous code only doing n- previous code answer

class Solution {
public:
	int dp[12][2][2048];

	int fn(int pos, int tight, int mask, vector<int>& digits) {
		int sz = digits.size();
		if (pos == sz)
			return mask ? 1 : 0;
		if (dp[pos][tight][mask] != -1)
			return dp[pos][tight][mask];

		int limit = (tight == 1) ? digits[pos] : 9;
		int res = 0;

		for (int i = 0; i <= limit; i++) {
			if (mask & (1 << i))
				continue;

			int newTight = (tight == 1 && i == limit) ? 1 : 0;
			if (mask == 0 && i == 0) {
				res += fn(pos + 1, newTight, mask, digits);
			} else {
				res += fn(pos + 1, newTight, (mask | (1 << i)), digits);
			}
		}

		return dp[pos][tight][mask] = res;
	}

	int compute(int x) {
		vector<int> digits;
		memset(dp, -1, sizeof(dp));
		while (x) {
			digits.push_back(x % 10);
			x = x / 10;
		}
		reverse(digits.begin(), digits.end());
		return fn(0, 1, 0, digits);
	}

	int numDupDigitsAtMostN(int n) {
		return n - compute(n);
	}
};
