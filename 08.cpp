#include <bits/stdc++.h>
using namespace std;

// compute the KMP "lps" table for pattern P
static vector<int> buildLPS(const string &P) {
    int m = P.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (P[i] == P[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len-1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

// return all start‑indices of P in T
static vector<int> kmpSearch(const string &P, const string &T) {
    int n = T.size(), m = P.size();
    vector<int> res;
    if (m == 0) {
        // empty P: match at every position
        res.reserve(n+1);
        for (int i = 0; i <= n; i++) res.push_back(i);
        return res;
    }
    auto lps = buildLPS(P);
    for (int i = 0, j = 0; i < n; ) {
        if (T[i] == P[j]) {
            i++; j++;
            if (j == m) {
                res.push_back(i - m);
                j = lps[j-1];
            }
        } else if (j) {
            j = lps[j-1];
        } else {
            i++;
        }
    }
    return res;
}

int findMaxRegexMatch(string sourceString, string pattern) {
    int n = sourceString.size();
    int star = pattern.find('*');
    string pre = pattern.substr(0, star);
    string suf = pattern.substr(star+1);
    int pl = pre.size(), sl = suf.size();

    // both empty => "*" => whole string
    if (pl == 0 && sl == 0) return n;

    auto prefPos = kmpSearch(pre, sourceString);
    auto sufPos  = kmpSearch(suf, sourceString);

    // suffix empty => pattern = pre* => longest = n - earliest pre
    if (sl == 0) {
        if (prefPos.empty()) return -1;
        return n - prefPos.front();
    }
    // prefix empty => pattern = *suf => longest = (latest suf end + 1)
    if (pl == 0) {
        if (sufPos.empty()) return -1;
        return sufPos.back() + sl;
    }

    if (prefPos.empty() || sufPos.empty()) return -1;
    int maxS = sufPos.back();
    int ans = -1;
    for (int i : prefPos) {
        // ensure suffix starts at or after prefix ends:
        if (maxS >= i + pl) {
            ans = max(ans, maxS + sl - i);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sourceString, pattern;
    // e.g. input:
    //   programming
    //   r*in
    if (!getline(cin, sourceString)) return 0;
    if (!getline(cin, pattern)) return 0;

    cout << findMaxRegexMatch(sourceString, pattern) << "\n";
    return 0;
}
