/*3628. Maximum Number of Subsequences After One Inserting

You are given a string s consisting of uppercase English letters.

You are allowed to insert at most one uppercase English letter at any position
(including the beginning or end) of the string.

Return the maximum number of "LCT" subsequences that can be formed
in the resulting string after at most one insertion
*/

class Solution {
public:
	long long numOfSubsequences(string s) {
		long long n = s.size();
		vector<long long> prefix(n + 1, 0), suffix(n + 1, 0);
		for (long long i = 1; i <= n; i++) {
			if (s[i - 1] == 'L') {
				prefix[i] = prefix[i - 1] + 1;
			} else {
				prefix[i] = prefix[i - 1];
			}
		}
		for (long long i = n - 1; i >= 0; i--) {
			if (s[i] == 'T') {
				suffix[i] = suffix[i + 1] + 1;
			} else {
				suffix[i] = suffix[i + 1];
			}
		}
		long long opL = 0;
		long long opT = 0;
		long long opC = 0;
		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			if (s[i - 1] == 'C') {
				opL += (prefix[i] + 1) * suffix[i];
				opT += prefix[i] * (suffix[i] + 1);
				ans += prefix[i] * suffix[i];
				opC = max(opC, prefix[i] * suffix[i]);
			} else {
				opC = max(opC, prefix[i] * suffix[i]);
			}
		}
		ans = max({opL, opT, ans + opC});
		return ans;

	}
};