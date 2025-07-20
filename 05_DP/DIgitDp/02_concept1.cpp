#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int dp[20][2][180];

int fn(int pos, int tight, int currsum, int sizelimit, vector<int>& digit_at_eachpos) {
	if (pos == sizelimit) {
		return currsum;
	}
	if (dp[pos][tight][currsum] != -1) {
		return dp[pos][tight][currsum];
	}

	int res = 0;

	if (tight == 1) {
		for (int i = 0; i <= digit_at_eachpos[pos]; ++i) {
			if (i == digit_at_eachpos[pos]) {
				res += fn(pos + 1, 1, currsum + i, sizelimit, digit_at_eachpos);
			}
			if (i < digit_at_eachpos[pos]) {
				res += fn(pos + 1, 0, currsum + i, sizelimit, digit_at_eachpos);
			}
		}
	}

	if (tight == 0) {
		for (int i = 0; i <= 9; ++i) {
			res += fn(pos + 1, 0, currsum + i, sizelimit, digit_at_eachpos);
		}
	}

	return 	dp[pos][tight][currsum] = res;

}

int compute(ll x) {
	if (x < 0) return 0;

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

void solve() {
	ll l, r;
	cin >> l >> r;
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

// ----------------------------------------------for sum of digits-------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

ll dp[20][2][180];

ll digit_sum(int pos, int tight, int currsum, const vector<int>& digits) {
	if (pos == digits.size()) {
		return currsum;
	}

	if (dp[pos][tight][currsum] != -1) {
		return dp[pos][tight][currsum];
	}

	int limit;
	if (tight == 1) {
		limit = digits[pos];
	} else {
		limit = 9;
	}

	ll res = 0;
	for (int dig = 0; dig <= limit; ++dig) {
		int new_tight;
		if (tight == 1 && dig == digits[pos]) {
			new_tight = 1;
		} else {
			new_tight = 0;
		}
		res += digit_sum(pos + 1, new_tight, currsum + dig, digits);
	}

	dp[pos][tight][currsum] = res;
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
	return digit_sum(0, 1, 0, digits);
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
