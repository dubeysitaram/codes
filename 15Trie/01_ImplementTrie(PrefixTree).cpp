/* 01_ImplementTrie(PrefixTree).cpp
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store
and retrieve keys in a dataset of strings. There are various applications of this data structure,
such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before),
and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously
inserted string word that has the prefix prefix, and false otherwise.
*/

struct Node {
	Node* links[26];
	bool flag = false;
	bool ContainKey(char ch) { return links[ch - 'a'] != NULL; }
	void PutKey(int ch, Node* node) { links[ch - 'a'] = node; }
	Node* GetNextNode(char ch) { return links[ch - 'a']; }
	bool SetEnd() { return flag = true; }
	bool IsEnd() { return flag; }
};

class Trie {
	Node* Root;

public:
	Trie() { Root = new Node(); }

	void insert(string word) {
		Node* temp = Root;
		for (int i = 0; i < word.size(); i++) {
			bool isPresent = temp->ContainKey(word[i]);
			if (!isPresent) {

				temp->PutKey(word[i], new Node());
			}
			temp = temp->GetNextNode(word[i]);
		}
		temp->SetEnd();
	}

	bool search(string word) {
		Node* temp = Root;
		for (int i = 0; i < word.size(); i++) {
			if (!temp->ContainKey(word[i])) {
				return false;
			}
			temp = temp->GetNextNode(word[i]);
		}
		if (temp->IsEnd())
			return true;
		return false;
	}

	bool startsWith(string prefix) {
		Node* temp = Root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!temp->ContainKey(prefix[i])) {
				return false;
			}
			temp = temp->GetNextNode(prefix[i]);
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */