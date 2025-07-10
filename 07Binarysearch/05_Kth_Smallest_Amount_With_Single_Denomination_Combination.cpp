// 3116. Kth_Smallest_Amount_With_Single_Denomination_Combination.cpp

/*
You are given an integer array coins representing coins of different denominations and an integer k.

You have an infinite number of coins of each denomination. 
However, you are not allowed to combine coins of different denominations.

Return the kth smallest amount that can be made using these coins.

Constraints:

1 <= coins.length <= 15
1 <= coins[i] <= 25
1 <= k <= 2 * 109
coins contains pairwise distinct integers.

*/

// using the exclusion inclusion principle
// count the numbers of integers smaller or equal to x without duplicates.

class Solution {
public:
	long long gcd(long long a, long long b) {
		return (b == 0 ? a : gcd(b, a % b));
	}

	long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

	long long ispossible(vector<int>& coins, long long x) {
		int size = coins.size();
		long long sum = 0;
		for (int mask = 1; mask < (1 << size); mask++) {
			// number of bits set on
			int bits = __builtin_popcountll(mask);
			long long leastComMul = 1;
			for (int j = 0; j < size; j++) {
				if (mask & (1 << j))
					leastComMul = lcm(leastComMul, coins[j]); // get the lcm for the subset
			}
			// inclusion exclusion applied here
			if (bits & 1) { // if is odd add ,otherwise subtract
				sum += x / leastComMul;
			}
			else {
				sum -= x / leastComMul;
			}
		}
		return sum;
	}


	long long findKthSmallest(vector<int>& coins, int k) {
		long long lo = 0, hi = 25LL * 2e9;
		while (hi - lo > 1) {
			long long mid = (hi + lo) / 2;
			if (ispossible(coins, mid) < k)
				lo = mid;
			else
				hi = mid;
		}
		return hi;
	}
};