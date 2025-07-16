// 687. Longest Univalue Path

/*
Given the root of a binary tree, return the length of the longest path,
where each node in the path has the same value. This path may or may not pass through the root.
The length of the path between two nodes is represented by the number of edges between them.

*/

/**
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
	int fn(TreeNode* root, int &maxi) {
		if (root == NULL)
			return 0;

		int leftmax = fn(root->left, maxi);
		int rightmax = fn(root->right, maxi);
		// case 1
		if (root->left != NULL && root->right != NULL && root->left->val == root->val && root->right->val == root->val) {
			maxi = max(maxi, 1 + leftmax + rightmax);
			return 1 + max(leftmax, rightmax);
		} // case 2
		else if (root->left != NULL && root->left->val == root->val) {
			maxi = max(maxi, 1 + leftmax);
			return 1 + leftmax;
		} // case 3
		else if (root->right != NULL && root->right->val == root->val) {
			maxi = max(maxi, 1 + rightmax);
			return 1 + rightmax;
		}//case 4
		else {
			maxi = max(maxi, 1);
			return 1;
		}
	}

	int longestUnivaluePath(TreeNode* root) {

		int maxi = 0;
		fn(root, maxi);
		return max(0, maxi - 1);
	}
};
