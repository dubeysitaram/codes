/*
02_ImpementTrie2.cpp
Problem statement
Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
Note:

1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Can you help Ninja implement the "TRIE" data structure?


*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* Links[26];   // Links to child nodes
	bool flag;          // Marks if a word ends here
	int cntEndwith  = 0;         // Tracks the number of words passing through a node (prefix frequency)
	int cntPrefix = 0;  // Tracks the number of times a word exactly ends at this node

	bool isKeyExist(char key) {
		return (Links[key - 'a'] != NULL);
	}

	void PuttheKey(char key, Node* node) {
		Links[key - 'a'] = node;
	}

	Node* Get(char key) {
		return Links[key - 'a'];
	}

	void setEnd() {
		flag = true;
	}
	void increaseEnd() {
		cntEndwith++;
	}
	void increasePrefix() {
		cntPrefix++;
	}
	void decreaseEnd() {
		cntEndwith--;
	}
	void decreasePrefix() {
		cntPrefix--;

	}

	bool isEnd() {
		return flag;
	}

};

class Trie {
	Node* root;

public:
	Trie() {
		root = new Node();
	}

	void insert(string &word) {
		Node* temp = root;
		for (int i = 0; i < word.size(); i++) {
			if (!temp->isKeyExist(word[i])) {
				temp->PuttheKey(word[i], new Node());
			}
			temp = temp->Get(word[i]);
			temp->increasePrefix(); // Increment prefix frequency at each node
		}
		temp->setEnd(); // Mark the end of the word
		temp->increaseEnd();
	}

	// Returns the number of times the word has been inserted into the trie
	int countWordsEqualTo(string &word) {
		Node* temp = root;
		for (int i = 0; i < word.size(); i++) {
			if (!temp->isKeyExist(word[i])) return 0;
			temp = temp->Get(word[i]);
		}
		if (temp->isEnd())
			return temp->cntEndwith; // Returns the exact count of the word at the last node
		return 0;
	}

	// Returns the number of words that start with the given prefix
	int countWordsStartingWith(string &word) {
		Node* temp = root;
		for (int i = 0; i < word.size(); i++) {
			if (!temp->isKeyExist(word[i])) return 0;
			temp = temp->Get(word[i]);
		}
		return temp->cntPrefix; // Returns the number of words with the prefix
	}

	// Removes a word from the trie
	void erase(string &word) {
		Node* temp = root;
		for (int i = 0; i < word.size(); i++) {
			if (temp->isKeyExist(word[i]))
			{	// Decrement prefix frequency
				temp = temp->Get(word[i]);
				temp->cntPrefix--;// ye upar wali line ke niche hi rahegaa
			}
			else return;
		}
		temp->cntEndwith--;

	}
};
