// 3116. Kth Smallest Amount With Single Denomination Combination
// // three muskeeters (hackker earth) luv sir



class Solution {

	long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }

	long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

	// using the exclusion inclusion principle
	// Count the numbers of integers smaller or equal to x without duplicates.
	long long count(vector<int>& coins, long long x) {
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
			if (bits & 1) // if is odd add otherwise subtract
				sum += x / leastComMul;
			else
				sum -= x / leastComMul;
		}
		return sum;
	}

public:
	long long findKthSmallest(vector<int>& coins, int k) {
		long long lo = 0, hi = 25LL * 2e9;
		while (hi - lo > 1) {
			long long mid = (hi + lo) / 2;
			if (count(coins, mid) < k)
				lo = mid;
			else
				hi = mid;
		}
		return hi;
	}
};