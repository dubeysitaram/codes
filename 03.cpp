class Solution {
public:
	const long long MOD = 1e9 + 7;
	long long n, totsum, totpermpossible;
	long long totalways = 0;

	long long binaryexpo(long long a, long long b) {
		if (b == 0) return 1;
		long long z = binaryexpo(a, b / 2);
		z = (z * z) % MOD;
		if (b & 1) z = (z * a) % MOD;
		return z;
	}

	void factorial(vector<long long>& fact) {
		fact.resize(n + 1);
		fact[0] = 1;
		for (long long i = 1; i <= n; i++)
			fact[i] = (i * fact[i - 1]) % MOD;
	}

	void fermat_fact(const vector<long long>& fact, vector<long long>& fermfact) {
		fermfact.resize(n + 1);
		for (long long i = 0; i <= n; i++)
			fermfact[i] = binaryexpo(fact[i], MOD - 2);
	}

	long long solve(long long currdig, long long evenposused, long long cursum, vector<long long>& fermfact, vector<long long>& freq) {

		if (currdig == 10) {
			if (cursum == totsum / 2 && evenposused == (n + 1) / 2)
				return totpermpossible;
			else
				return 0;
		}

		long long ans = 0;
		for (long long count = 0; count <= min(freq[currdig], (n + 1) / 2 - evenposused); count++) {
			long long evensame = count;
			long long oddsame = freq[currdig] - count;

			long long div = (fermfact[evensame] * fermfact[oddsame]) % MOD;
			long long val = solve(currdig + 1, evenposused + evensame,
			                      cursum + evensame * currdig, fermfact, freq);

			ans = (ans + (val * div) % MOD) % MOD;
		}
		return ans;
	}

	int countBalancedPermutations(string nums) {
		n = nums.size();
		totsum = 0;
		sort(nums.begin(), nums.end());
		vector<long long> freq(10, 0);
		for (char ch : nums) {
			long long x = ch - '0';
			totsum += x;
			freq[x]++;
		}
		if (totsum % 2) return 0;

		vector<long long> fact, fermfact;
		factorial(fact);
		fermat_fact(fact, fermfact);

		totpermpossible = (fact[(n + 1) / 2] * fact[n / 2]) % MOD;
		long long currdig = 0, evenposused = 0, cursum = 0;
		return solve(0, 0, 0, fermfact, freq);
	}
};
