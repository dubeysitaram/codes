class Solution {
public:
    bool ispossible(int mid, unordered_map<char, int>& mp2, string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < mid; i++) {
            freq[s[i]]++;
        }
        bool flag = true;
        for (auto it : mp2) {
            if (freq[it.first] < it.second) {
                flag = false;
            }
        }
        if (flag) return true;

        for (int i = mid; i < s.size(); i++) {
            freq[s[i - mid]]--;
            freq[s[i]]++;
            flag = true;
            for (auto it : mp2) {
                if (freq[it.first] < it.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> mp1, mp2;

        for (char c : s) mp1[c]++;
        for (char c : t) mp2[c]++;

        for (char c : t) {
            if (mp2[c] > mp1[c]) return "";
        }

        int lo = m - 1, hi = n;

        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (ispossible(mid, mp2, s)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        unordered_map<char, int> freq;
        for (int i = 0; i < hi; i++) {
            freq[s[i]]++;
        }
        bool flag = true;
        for (auto it : mp2) {
            if (freq[it.first] < it.second) {
                flag = false;
            }
        }
        if (flag) return s.substr(0, hi);

        for (int i = hi; i < n; i++) {
            freq[s[i - hi]]--;
            freq[s[i]]++;
            flag = true;
            for (auto it : mp2) {
                if (freq[it.first] < it.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) return s.substr(i - hi + 1, hi);
        }

        return "";
    }
};