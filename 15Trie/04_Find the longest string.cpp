/* 04_Find the longest string.cpp
Given an array of strings words[]. Find the longest string in words[]
such that every prefix of it is also present in the array words[].

Note: If multiple strings have the same maximum length, return the lexicographically smallest one.
*/



struct Node {
	Node* links[26];
	bool flag = false;
	int cntPrefix = 0;
	int cntEndWith = 0;
	bool ContainKey(char ch) { return links[ch - 'a'] != NULL; }
	void PutKey(int ch, Node* node) { links[ch - 'a'] = node; }
	Node* GetNextNode(char ch) { return links[ch - 'a']; }
	bool SetEnd() { return flag = true; }
	bool IsEnd() { return flag; }
	void IncEnd() { cntEndWith++; }
	void IncPrefix() { cntPrefix++; }
	void DecEnd() { cntEndWith--; }
	void DecPrefix() { cntPrefix--; }
};

class Trie {
	Node* Root;
public:
	Trie() { Root = new Node(); }
	Node* GetRootofTrie() {
		return Root;
	}
	void insert(string word) {
		Node* temp = Root;
		for (int i = 0; i < word.size(); i++) {
			if (!temp->ContainKey(word[i])) {
				temp->PutKey(word[i], new Node());
			}
			temp = temp->GetNextNode(word[i]);
		}
		temp->SetEnd();
	}
};
// har word ke har charchetr prr isEnd ko true krte jayenge insert krte wqt hi
// and then for each string we will check wether isEnd is true and also we will check
// is the given word is present or not
class Solution {
public:
	Trie trie;
	string longestString(vector<string>& words) {
		int n = words.size();
		for (int i = 0; i < n; i++) {
			trie.insert(words[i]);
		}
		sort(words.begin(), words.end());
		string ans = "";
		for (int i = 0; i < n; i++) {
			Node* temp = trie.GetRootofTrie();
			bool ispossible = true;
			for (int j = 0; j < words[i].size(); j++) {
				if (!temp->ContainKey(words[i][j])) {
					ispossible = false;
					break;
				}
				temp = temp->GetNextNode(words[i][j]);
				if (!temp->IsEnd()) {
					ispossible = false;
					break;
				}
			}
			if (ispossible) {
				if (words[i].size() > ans.size()) {
					ans = words[i];
				}
			}
		}
		return ans;
	}
};
