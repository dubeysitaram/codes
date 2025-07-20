// 357. Count Numbers with Unique Digits

/*
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n.

*/
// yaha mask ban leneg inorder to capture which digit is used and which not

class Solution {
public:
	int dp[12][2][2048];

	int fn(int pos, int tight, int mask, vector<int>& digits) {
		int sz = digits.size();
		if (pos == sz)
			return mask ? 1 : 0;
		if (dp[pos][tight][mask] != -1)
			return dp[pos][tight][mask];

		int limit = (tight == 1) ? digits[pos] : 9; // standard tarika hai
		int res = 0;

		for (int i = 0; i <= limit; i++) {
			if (mask & (1 << i))
				continue;

			int newTight = (tight == 1 && i == limit) ? 1 : 0;  // standard tarika yahi likhna hai
			if (mask == 0 && i == 0) { /// yahaa dhyan dena hai
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
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1;
		return compute((int)pow(10, n) - 1) + 1;
	}
};

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// code with explanation


class Solution {
public:
	// dp[pos][tight][mask] - memoization table
	// pos: current digit index
	// tight: whether current prefix is equal to the prefix of original number
	// mask: bitmask to keep track of digits used
	int dp[12][2][2048];

	// Recursive Digit DP function
	int fn(int pos, int tight, int mask, vector<int>& digits) {
		int sz = digits.size();

		// Base case: if we've placed all digits
		// return 1 if any digit was placed (mask != 0), else 0
		if (pos == sz)
			return mask ? 1 : 0;

		if (dp[pos][tight][mask] != -1)
			return dp[pos][tight][mask];

		// Determine the upper limit of the current digit
		int limit = (tight == 1) ? digits[pos] : 9;
		int res = 0;

		// Try placing each digit from 0 to limit
		for (int i = 0; i <= limit; i++) {
			// Skip if digit i is already used
			if (mask & (1 << i))
				continue;

			// Update tight constraint
			int newTight = (tight == 1 && i == limit) ? 1 : 0;

			// Skip leading zeros — don't set bit in mask
			if (mask == 0 && i == 0) {
				res += fn(pos + 1, newTight, mask, digits);
			} else {
				// Include digit i and mark it used in mask
				res += fn(pos + 1, newTight, (mask | (1 << i)), digits);
			}
		}

		// Memoize and return result
		return dp[pos][tight][mask] = res;
	}

	// Wrapper to convert number to digit array and reset DP
	int compute(int x) {
		vector<int> digits;
		memset(dp, -1, sizeof(dp));

		// Extract digits from number x
		while (x) {
			digits.push_back(x % 10);
			x = x / 10;
		}
		reverse(digits.begin(), digits.end());

		return fn(0, 1, 0, digits);
	}

	// Count numbers with unique digits up to 10^n - 1
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1; // only 0 is valid
		return compute((int)pow(10, n) - 1) + 1; // +1 to include 0
