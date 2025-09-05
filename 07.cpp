#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortestSubstring(string s, int k) {
	int n = s.length();
	vector<int> count(26, 0);

	// Step 1: Check feasibility (does string have at least k unique chars?)
	int uniqueTotal = 0;
	for (char c : s) {
		if (count[c - 'a'] == 0) uniqueTotal++;
		count[c - 'a']++;
	}
	if (uniqueTotal < k) return -1;  // not possible

	// Reset frequency array for sliding window
	fill(count.begin(), count.end(), 0);

	int left = 0;            // left pointer of window
	int uniqueNow = 0;       // how many unique chars are in current window
	int ans = INT_MAX;       // store min length answer

	// Step 2: Expand window using right pointer
	for (int right = 0; right < n; right++) {
		if (count[s[right] - 'a'] == 0) uniqueNow++;  // new unique char enters
		count[s[right] - 'a']++;

		// Step 3: Shrink window from left if we already have k unique
		while (uniqueNow >= k) {
			ans = min(ans, right - left + 1);  // update minimum length
			count[s[left] - 'a']--;            // remove left char
			if (count[s[left] - 'a'] == 0)     // if unique char count becomes 0
				uniqueNow--;                   // reduce unique count
			left++;                            // shrink window
		}
	}

	// Step 4: return result
	return (ans == INT_MAX ? -1 : ans);
}

int main() {
	string s;
	int k;
	cin >> s >> k;  // Input string and k
	cout << shortestSubstring(s, k) << endl;
	return 0;
}
