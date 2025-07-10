// 60. Permutation Sequence
/*

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(10, 1);
        for (int i = 1; i < 10; i++) {
            fact[i] = i * fact[i - 1];
        }
        int ct = 0;
        vector<int> vis(10, 0);
        string ans;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (vis[i])
                    continue;
                if (ct + fact[n - j] < k) {
                    ct += fact[n - j];
                    continue;
                } else {
                    ans.push_back(i + '0');
                    vis[i] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};

