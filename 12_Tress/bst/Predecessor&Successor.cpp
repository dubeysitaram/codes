// Predecessor&Successor.cpp

/*

You are given root node of the BST and an integer key.
You need to find the in-order successor and predecessor of the given key.
If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor
and the number just greater than the target is the successor.
*/


/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
public:
	void successor(Node* root, int key, int& val) {
		if (root == NULL) return;
		if (root->key == key) {
			successor(root->right, key, val);
		} else if (root->key > key && root->key < val) {
			val = min(root->key, val);
			successor(root->left, key, val);
		} else if (root->key < key) {
			successor(root->right, key, val);
		}
	}

	void predecessor(Node* root, int key, int& val) {
		if (root == NULL) return;
		if (root->key == key) {
			predecessor(root->left, key, val);
		} else if (root->key > key) {
			predecessor(root->left, key, val);
		} else if (root->key < key && root->key > val) {
			val = max(val, root->key);
			predecessor(root->right, key, val);
		}
	}

	void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
		int val1 = INT_MAX, val2 = INT_MIN;
		successor(root, key, val1);
		predecessor(root, key, val2);
		pre = (val2 != INT_MIN) ? new Node(val2) : new Node(-1);
		suc = (val1 != INT_MAX) ? new Node(val1) : new Node(-1);
	}

};

