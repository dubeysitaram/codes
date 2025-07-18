// Remove K Digits
/*
Given string num representing a non-negative integer num, and an integer k,
return the smallest possible integer after removing k digits from num.
*/

class Solution {
public:
	string removeKdigits(string num, int k) {
		int n = num.size();
		stack<char>st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && k > 0 && num[i] < st.top()) {st.pop(); k--;}
			st.push(num[i]);
		}
		while (k--) {
			st.pop();
		}

		string ans;
		bool flag = true;
		while (!st.empty()) {

			ans.push_back(st.top());
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		string finalans;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == '0' && flag == true)continue;
			else {
				finalans.push_back(ans[i]);
				flag = false;
			}
		}

		return finalans.empty() ? "0" :  finalans;
	}
};


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

tuple<int, int, int, int, int> maxSumSubmatrix(vector<vector<int>>& mat) {
	int rows = mat.size(), cols = mat[0].size();
	int maxSum = INT_MIN;
	int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;

	for (int left = 0; left < cols; ++left) {
		vector<int> temp(rows, 0);

		for (int right = left; right < cols; ++right) {
			for (int i = 0; i < rows; ++i)
				temp[i] += mat[i][right];

			int currSum = temp[0], maxTemp = temp[0];
			int start = 0, top = 0, bottom = 0;

			for (int i = 1; i < rows; ++i) {
				if (currSum < 0) {
					currSum = temp[i];
					start = i;
				} else {
					currSum += temp[i];
				}

				if (currSum > maxTemp) {
					maxTemp = currSum;
					top = start;
					bottom = i;
				}
			}

			if (maxTemp > maxSum) {
				maxSum = maxTemp;
				finalLeft = left;
				finalRight = right;
				finalTop = top;
				finalBottom = bottom;
			}
		}
	}

	return {maxSum, finalTop, finalLeft, finalBottom, finalRight};
}


