/*
1707_Max_XOR_With_Element_From_Arr.cpp

You are given an array nums consisting of non-negative integers.
You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi
and any element of nums that does not exceed mi.
In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi.
If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.
length and answer[i] is the answer to the ith query.

*/

struct Node {
	Node* links[2];
	bool containskey(int bit) { return links[bit] != NULL; }
	Node* Getnextnode(int bit) { return links[bit]; }
	void PutTheNode(int bit, Node* node) { links[bit] = node; }
};

class Trie {
	Node* root = new Node();

public:
	void insert(int num) {
		Node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (!temp->containskey(bit)) {
				temp->PutTheNode(bit, new Node());
			}
			temp = temp->Getnextnode(bit);
		}
	}

	int Getmax_xorofnums(int num) {
		Node* temp = root;
		int maxNum = 0;
		for (int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (temp->containskey(1 - bit)) {
				maxNum |= (1 << i);
				temp = temp->Getnextnode(1 - bit);
			} else {
				temp = temp->Getnextnode(bit);
			}
		}
		return maxNum;
	}
};

class Solution {
public:
	vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		int m = queries.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>>sortedquery(m, vector<int>(3));
		for (int i = 0; i < m; i++) {
			sortedquery[i] = {queries[i][1], queries[i][0], i};
		}
		sort(sortedquery.begin(), sortedquery.end());
		Trie trie;
		int i = 0;
		vector<int> ans(m, -1);
		for (int j = 0; j < sortedquery.size(); j++) {
			while (i < n && nums[i] <= sortedquery[j][0]) {
				trie.insert(nums[i]);
				i++;
			}
			if (i != 0)ans[sortedquery[j][2]] = trie.Getmax_xorofnums(sortedquery[j][1]);
		}

		return ans;
	}
};