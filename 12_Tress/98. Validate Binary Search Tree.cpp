// 98. Validate Binary Search Tree.cpp
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.


*/

class Solution {
public:
	bool fn(TreeNode* root, long long left, long long right) {
		if (root == nullptr)
			return true;
		if (root->val >= right || root->val <= left)
			return false;
		bool leftans = fn(root->left, left, root->val);
		bool rightans = fn(root->right, root->val, right);
		if (leftans && rightans)
			return true;
		return false;
	}
	bool isValidBST(TreeNode* root) {
		return fn(root, -1e12, 1e12);
	}
};