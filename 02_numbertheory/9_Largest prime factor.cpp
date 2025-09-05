// 9_Largest prime factor.cpp
/*
Given a number n, your task is to find the largest prime factor of n.
*/

class Solution {
public:
	int ans;
	int largestPrimeFactor(int n) {
		if (n % 2 == 0)ans = 2;
		while (n % 2 == 0)n = n / 2;
		for (int i = 3; i * i <= n; i += 2) {
			if (n % i == 0)ans = i;
			while (n % i == 0)n = n / i;
		}
		if (n > 2)ans = n;
		return ans;

	}
};