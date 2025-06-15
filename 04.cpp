#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

int compute_min_dif()
class Solution {
public:
	bool findsmall(char ch, vector<int>& freq) {
		for (int i = 0; i < ch - 'a'; i++) {
			if (freq[i] != 0)
				return true;
		}
		return false;
	}
	string robotWithString(string s) {
		int n = s.size();
		vector<int> freq(26, 0);
		for (int i = 0; i < n; i++) {
			freq[s[i] - 'a']++;
		}
		string t;
		string ans;
		int i = 0;
		while (i < n) {
			if (t.size() == 0) {t.push_back(s[i]); i++; continue;}
			char last = t.back();
			if (s[i] > last) {t.push_back(s[i]); i++; continue;}

			if (findsmall(last, freq)) {t.push_back(s[i]); i++; continue;}
			ans.push_back(last);
			t.pop_back();
			i++;
		}
		reverse(t.begin(), t.end());
		ans = ans + t;
		return ans;
	}
};

void solve() {


}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}