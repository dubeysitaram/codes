// 902. Numbers At Most N Given Digit Set.cpp
/*
Given an array of digits which is sorted in non-decreasing order.
You can write numbers using each digits[i] as many times as we want.
For example, if digits = ['1','3','5'],we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.
*/

class Solution {
public:
	int dp[10][2];

	int fn(int pos, int tight, vector<int>& arr, vector<int>& numberdig) {
		if (pos == numberdig.size())
			return 1;

		if (dp[pos][tight] != -1)
			return dp[pos][tight];

		int limit = tight ? numberdig[pos] : 9;
		int res = 0;

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] > limit) continue;
			int newtight = (tight == 1 && arr[i] == limit) ? 1 : 0;
			res += fn(pos + 1, newtight, arr, numberdig);
		}

		return dp[pos][tight] = res;
	}

	int atMostNGivenDigitSet(vector<string>& digits, int n) {
		vector<int> arr, numberdig;

		for (string& s : digits)
			arr.push_back(stoi(s));

		while (n) {
			numberdig.push_back(n % 10);
			n /= 10;
		}
		reverse(numberdig.begin(), numberdig.end());

		// Step 1: count numbers with length < numberdig.size()
		int res = 0;
		int len = numberdig.size();
		int d = arr.size();
		for (int i = 1; i < len; i++)
			res += pow(d, i);

		// Step 2: count numbers with length == numberdig.size()
		memset(dp, -1, sizeof(dp));
		res += fn(0, 1, arr, numberdig);

		return res;
	}
};
