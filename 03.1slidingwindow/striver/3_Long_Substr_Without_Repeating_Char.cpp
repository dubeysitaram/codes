/* 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int i = 0;
		int j = 0;
		vector<int> v(128, 0);
		int ans = 0;
		while (j < n) {
			char pos = s[j];
			if (v[pos] < 1) {
				v[pos]++;
				ans = max(ans, j - i + 1);
				j++;

			} else {
				char pos2 = s[i];
				v[pos2]--;
				i++;
			}
		}
		return ans;
	}
};