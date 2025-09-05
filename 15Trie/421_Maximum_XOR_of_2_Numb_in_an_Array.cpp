// 421_Maximum_XOR_of_2_Numb_in_an_Array.cpp
/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.


*/

struct Node {
	Node* links[2];
	bool flag = false;
	void PutKey(int bit, Node* node) { links[bit] = node; }
	bool isKeyPresent(int bit) { return links[bit] != NULL; }
	Node* GetNextNode(int bit) { return links[bit]; }
};
class Trie {
	Node* Root;

public:
	Trie() { Root = new Node(); }
	void InsertNumber(int nums) {
		Node* temp = Root;
		for (int i = 31; i >= 0; i--) {
			int bit = (nums >> i) & (1);
			if (!temp->isKeyPresent(bit)) {
				temp->PutKey(bit, new Node());
			}
			temp = temp->GetNextNode(bit);
		}
	}
	int MaxXorOfGivenNumber(int nums) {
		Node* temp = Root;
		int MaxNum = 0;
		for (int i = 31; i >= 0; i--) {
			int bit = (nums >> i) & (1);
			if (temp->isKeyPresent(1 - bit)) {
				MaxNum |= (1 << i);
				temp = temp->GetNextNode(1 - bit);

			} else {
				temp = temp->GetNextNode(bit);
			}
		}
		return MaxNum;
	}
};
class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		Trie trie;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			trie.InsertNumber(nums[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, trie.MaxXorOfGivenNumber(nums[i]));
		}
		return ans;
	}
};