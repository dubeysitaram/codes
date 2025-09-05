/* 701. Insert into a Binary Search Tree.cpp
You are given the root node of a binary search tree (BST) and a value to insert into the tree.
 Return the root node of the BST after the insertion.
 It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion,
as long as the tree remains a BST after insertion. You can return any of them.


/**
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
	void fn(TreeNode* root, int x) {
		if (root == nullptr)
			return;
		if (root->left == nullptr && root->right == nullptr) {
			if (root->val > x) {
				root->left = new TreeNode(x);
				return;
			} else {
				root->right = new TreeNode(x);
				return;
			}
		}
		if (root->left == nullptr && root->right != nullptr) {
			if (root->val > x) {
				root->left = new TreeNode(x);
				return;
			}
		}
		if (root->left != nullptr && root->right == nullptr) {
			if (x > root->val) {
				root->right = new TreeNode(x);
				return;
			}
		}
		if (root->val < x) {
			insertIntoBST(root->right, x);
		} else {
			insertIntoBST(root->left, x);
		}
	}
	TreeNode* insertIntoBST(TreeNode* root, int x) {
		if (root == nullptr)return new TreeNode(x);
		fn(root, x);
		return root;
	}
};
