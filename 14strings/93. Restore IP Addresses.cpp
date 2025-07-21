/*
93. Restore IP Addresses(String+Backtracking)

A valid IP address consists of exactly four integers separated by single dots.
Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses,
 but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses
 that can be formed by inserting dots into s.
 You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.


*/

class Solution {
public:
	bool ISVALID_IP(string &s) {
		string temp = "";
		int count = 0;
		int n = s.size();
		for (int i = 0; i <= n; i++) {
			if (i >= n || s[i] == '.') {
				if (temp.empty() || (temp.size() > 1 && temp[0] == '0') || temp.size() > 3)
					return false;
				for (char c : temp)
					if (!isdigit(c))
						return false;
				int num = stoi(temp);
				if (num < 0 || num > 255)
					return false;
				temp = "";
				count++;

			} else {
				temp += s[i];
			}
		}
		return count == 4;
	}
	vector<string> ans;
	void fn(string &s, string &temp, int i) {
		int n = s.size();
		if (i >= n) {
			if (ISVALID_IP(temp)) {
				ans.push_back(temp);
			}
			return;
		}
		temp += s[i];
		fn(s, temp, i + 1);
		temp.pop_back();
		temp += '.' ;
		temp += s[i];
		fn(s, temp, i + 1);
		temp.pop_back();
		temp.pop_back();
	}
	vector<string> restoreIpAddresses(string s) {
		string temp = "";
		fn(s, temp, 0);
		return ans;
	}
};