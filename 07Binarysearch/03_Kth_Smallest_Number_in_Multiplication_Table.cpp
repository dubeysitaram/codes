/*
Nearly everyone has used the Multiplication Table.
The multiplication table of size m x n is an integer matrix mat
where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k,
return the kth smallest element in the m x n multiplication table.

Constraints:

1 <= m, n <= 3 * 10^4
1 <= k <= m * n

*/
// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/solutions/5379213/general-technique-kth-smallest-any-problem-binary-search-more-practice-problems/
class Solution {
public:
  int findKthNumber(int m, int n, int k) {

    auto ispossible = [&](int x) {
      int ct = 0;
      for (int i = 1; i <= n; ++i) {
        int req_m_val = x / i;
        if (req_m_val < 1)
          break;
        ct += min(req_m_val, m);
        if (ct >= k)
          return true;
      }
      return false;
    };

    int lo = 0;
    int hi = m * n;
    while (hi - lo > 1) {
      int mid = (hi + lo) / 2;
      if (ispossible(mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    return hi;
  }
};