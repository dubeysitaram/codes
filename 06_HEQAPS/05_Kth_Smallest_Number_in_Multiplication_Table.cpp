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

// this solution will not work as the constaraaints are high m*n = 9*10^8 approx = 10^9
class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		multiset<int> ms;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (ms.size() < k)
					ms.insert(i * j);
				else {
					if (*ms.rbegin() > i * j) {
						ms.erase(prev(ms.end()));
						ms.insert(i * j);
					}
				}
			}
		}
		return *ms.rbegin();
	}
};

// second solution is using the standard template of the binary search


/*
Intuition
The naive approach is to calculate all the possible values.
Store them in an array, sort them and return the kth element.
But this approach will generally give TLE or memory limit exceeded.

Metric is the same as the answer that we are calculating.
Kth smallest of What ? (Metric)

Example metrics:
subarray sum,
product of pairs in same array,
no. of distinct elements in subarray

Corresponding problems are:
Kth smallest subarray sum,
Kth smallest pair product in an array,
Kth smallest count of distinct elements in subarray.


Instead of answering the question:
What is the Kth ranked metric ?

Can we calculate the rank of any given metric value ?

In this type of problems we should be always be able to count:

No. of items having metric lesser than X (an integer)
How many items are there having metric less than X ?

If we are able to count this, we have solved the problem.

We will then Binary Search over the range of possible values of the metric and
find the smallest value for which function countItemsHavingMetricLessThan(x) or
rankOfMetricValue(x) is equal or greater than K.





*/

//Approach

// The general solution looks like this: Template of the code

long long getCountOfItemsHavingMetricLessThan(long long x) {

}

long long findKthMetric(int k, other parameters in the problem) {
	long long lo = 1, hi = 1e18; // max possible value of the answer / metric

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		int count = getCountOfItemsHavingMetricLessThan(mid);
		if (count >= k) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}


// final solution ----->

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