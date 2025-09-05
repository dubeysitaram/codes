/* 104_Maximum Depth of Binary Tree.cpp

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node
down to the farthest leaf node.

*/

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)return 0;
		if (root->left == NULL && root->right == NULL)return 1;
		int l = maxDepth(root->right);
		int r = maxDepth(root->left);
		return 1 + max(l, r);
	}
};