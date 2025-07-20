/*
 1) range [l,r]
 2) [l,r] sum of digits of each number in the given range
 3) l,r<=  10^18

*/


#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

// dp[pos][flag][currsum] will store the result for a given state:
// pos = current digit position we're solving
// flag = whether the number formed so far is tight with the original number
// currsum = current sum of digits collected so far
int dp[20][2][180];

// Recursive DP function to calculate sum of digits for numbers <= the number formed by digit_at_eachpos
int fn(int pos, int flag, int currsum, int sizelimit, vector<int>& digit_at_eachpos) {
	// If we've filled all digits, return the sum collected so far
	if (pos == sizelimit) {
		return currsum;
	}

	// Return the already computed value to avoid re-computation (memoization)
	if (dp[pos][flag][currsum] != -1) {
		return dp[pos][flag][currsum];
	}

	int res = 0;

	// If we are still matching the original number (tight bound)
	if (flag == 1) {
		// We can only place digits from 0 to the current digit of original number
		for (int i = 0; i <= digit_at_eachpos[pos]; ++i) {
			int new_flag;

			// If current digit i is equal to digit in original number, we stay tight
			if (i == digit_at_eachpos[pos]) {
				new_flag = 1;
			}

			// If it's smaller, we are no longer tight (we can place any digits freely next)
			if (i < digit_at_eachpos[pos]) {
				new_flag = 0;
			}

			// Recurse to next digit position with updated sum and flag
			res += fn(pos + 1, new_flag, currsum + i, sizelimit, digit_at_eachpos);
		}
	}

	// If we are already free to use any digit (flag == 0), we can place 0-9 at current position
	if (flag == 0) {
		for (int i = 0; i <= 9; ++i) {
			res += fn(pos + 1, 0, currsum + i, sizelimit, digit_at_eachpos);
		}
	}

	// Save and return result
	dp[pos][flag][currsum] = res;
	return res;
}

// Compute total sum of digits for all numbers from 1 to x
int compute(ll x) {
	// For 0 or negative, return 0
	if (x < 0) return 0;

	vector<int> digit_at_eachpos;

	// Break the number x into digits and store them in a vector
	while (x > 0) {
		digit_at_eachpos.push_back(x % 10);
		x /= 10;
	}

	// Since we built digits in reverse, reverse to get correct order (most significant to least)
	reverse(digit_at_eachpos.begin(), digit_at_eachpos.end());

	int sizelimit = digit_at_eachpos.size();

	// Clear the dp array before using it
	memset(dp, -1, sizeof(dp));

	// Call the recursive digit DP
	return fn(0, 1, 0, sizelimit, digit_at_eachpos);
}

// Solve a single test case: print sum of digits of all numbers from l to r
void solve() {
	ll l, r;
	cin >> l >> r;

	// Use compute() for r and l-1 to get sum in range [l, r]
	int ans = compute(r) - compute(l - 1);
	cout << ans << "\n";
}

int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
