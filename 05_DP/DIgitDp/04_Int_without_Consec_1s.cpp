//600 Non-negative Integers without Consecutive Ones

/*

Given a positive integer n, return the number of the integers in the range [0, n]
 whose binary representations do not contain consecutive ones.
*/
//  yaha humne digit ko 0 ya 1 hona hi allowed kia ha agr number not containing the digit x
// as consecutive the hum prevbin prevdig lelte aur limit 9 tak hojaati (nicche solution likha hai)
class Solution {
public:
	typedef long long ll;
	ll dp[35][2][2];

	ll fn(int pos, int tight, int prevbin, const vector<int>& number_binary) {
		int sz = number_binary.size();
		if (pos == sz)
			return 1;
		if (dp[pos][tight][prevbin] != -1)
			return dp[pos][tight][prevbin];

		int limit = (tight == 1) ? number_binary[pos] : 1;
		ll res = 0;

		for (int i = 0; i <= limit; i++) {
			if (i == 1 && prevbin == 1)
				continue;

			if (i == limit && tight == 1)
				res += fn(pos + 1, 1, i, number_binary);
			else
				res += fn(pos + 1, 0, i, number_binary);
		}

		return dp[pos][tight][prevbin] = res;
	}

	ll compute(ll x) {
		vector<int> number_binary;
		while (x) {
			number_binary.push_back(x % 2);
			x /= 2;
		}
		reverse(number_binary.begin(), number_binary.end());
		memset(dp, -1, sizeof(dp));
		return fn(0, 1, 0, number_binary);
	}

	int findIntegers(int n) {
		return compute(n);
	}
};



// ----------------------solution for a digit x should not be consecutive--------------------------

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

ll dp[20][2][11]; // dp[pos][tight][prev_digit]

ll count_valid(int pos, int tight, int prev, const vector<int>& digits) {
	if (pos == digits.size()) {
		return 1; // valid number formed
	}

	if (dp[pos][tight][prev] != -1) {
		return dp[pos][tight][prev];
	}

	int limit;
	if (tight == 1) {
		limit = digits[pos];
	}
	if (tight == 0) {
		limit = 9;
	}

	ll res = 0;
	for (int dig = 0; dig <= limit; ++dig) {
		if (prev == 6 && dig == 6) {
			continue; // skip this number: contains "66"
		}

		int new_tight;
		if (tight == 1 && dig == digits[pos]) {
			new_tight = 1;
		}
		if (tight == 1 && dig < digits[pos]) {
			new_tight = 0;
		}
		if (tight == 0) {
			new_tight = 0;
		}

		res += count_valid(pos + 1, new_tight, dig, digits);
	}

	dp[pos][tight][prev] = res;
	return res;
}

ll compute(ll x) {
	if (x < 0) return 0;

	vector<int> digits;
	while (x > 0) {
		digits.push_back(x % 10);
		x /= 10;
	}
	reverse(digits.begin(), digits.end());

	memset(dp, -1, sizeof(dp));
	return count_valid(0, 1, 10, digits); // prev=10 means "no digit yet"
}

void solve() {
	ll l, r;
	cin >> l >> r;
	ll ans = compute(r) - compute(l - 1);
	cout << ans << "\n";
}

int main() {
	fastio();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
