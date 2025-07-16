// 112. Path Sum
/*
Given the root of a binary tree and an integer targetSum,
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
*/
class Solution {
public:
	bool dfs(TreeNode* root, int targetSum, int cursum) {
		if (root == NULL)return false;
		cursum += root->val;
		if (cursum == targetSum && root->left == NULL && root->right == NULL)return true;
		bool ans = false;
		if (root->left)ans |= dfs(root->left, targetSum, cursum);
		if (root->right)ans |= dfs(root->right, targetSum, cursum);
		cursum = cursum - root->val;
		return ans;
	}
	bool hasPathSum(TreeNode* root, int targetSum) {
		int cursum = 0;
		return dfs(root, targetSum, cursum);
	}
};