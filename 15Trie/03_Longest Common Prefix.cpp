/*
03_Longest Common Prefix.cpp
You are given an array ‘ARR’ consisting of ‘N’ strings.
Your task is to find the longest common prefix among all these strings.
If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after
removing some or all characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.
*/

struct Node {
	Node* links[26];
	bool flag = false;
	bool contain_key(char ch) { return links[ch - 'a'] != NULL; }
	void Put_Char(char ch, Node* node) { links[ch - 'a'] = node; }
	Node* Get_Next_Node(char ch) { return links[ch - 'a']; }
	bool setEnd() { return flag = true; }
	bool isEnd() { return flag; }
};

class Trie {


public:
	Node* root;
	Trie() { root = new Node(); }

	void insert(string word) {
		Node* node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->contain_key(word[i])) {
				node->Put_Char(word[i], new Node());
			}
			node = node->Get_Next_Node(word[i]);
		}
		node->setEnd();
	}

};
string longestCommonPrefix(vector<string> &strs, int n)
{
	Trie trie;
	if (strs.empty()) return "";
	for (string& str : strs) {
		if (str.empty()) return "";
		trie.insert(str);
	}

	Node* temp = trie.root;
	string ans = "";
	while (true) {
		int ct = 0;
		char ch;
		Node* next = nullptr;

		for (int i = 0; i < 26; i++) {
			if (temp->links[i] != NULL) {
				ct++;
				ch = i + 'a';
				next = temp->links[i];
			}
		}

		if (ct == 1 && !temp->isEnd()) {
			ans.push_back(ch);
			temp = next;
		} else break;
	}
	return ans;
}



//--------------------------method 2 -----------------------------------------------------------
// here we will take string at index 0 as ourr base string and compare other string to which amx j can go
string longestCommonPrefix(vector<string> &strs, int n) {
	if (strs.empty()) return "";

	string prefix = strs[0];
	for (int i = 1; i < n; i++) {
		int j = 0;
		while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
			j++;
		}
		prefix = prefix.substr(0, j);
		if (prefix == "") return "";
	}
	return prefix;
}


