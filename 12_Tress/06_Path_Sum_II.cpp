// 113. Path_Sum_II
/*
Given the root of a binary tree and an integer targetSum,
return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

*/

class Solution {
public:
	vector<vector<int>> ans;
	void dfs(TreeNode* root, int targetSum, int currsum, vector<int>& v) {
		if (root == NULL)return;
		if (root->left == NULL && root->right == NULL) {
			currsum += root->val;
			if (currsum == targetSum) {
				v.push_back(root->val);
				ans.push_back(v);
				v.pop_back();
				return;
			}
			return;
		}
		v.push_back(root->val);
		if (root->left) {
			dfs(root->left, targetSum, currsum + root->val, v);
		}
		if (root->right) {
			dfs(root->right, targetSum, currsum + root->val, v);
		}
		v.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> v;
		int currsum = 0;
		dfs(root, targetSum, currsum, v);
		return ans;
	}
};