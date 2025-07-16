// 437. Path_Sum_III

class Solution {
public:
	int ans = 0;
	void dfs(TreeNode* root, int targetSum, long long currsum) {

		if (root == NULL)
			return;
		currsum += root->val;
		if (currsum == targetSum) {
			ans++;
		}
		if (root->left == NULL && root->right == NULL) {
			return;
		}
		if (root->left) {
			dfs(root->left, targetSum, currsum);
		}
		if (root->right) {
			dfs(root->right, targetSum, currsum);
		}
	}
	int pathSum(TreeNode* root, int targetSum) {

		dfs(root, targetSum, 0LL);
		if (root != NULL && root->left != NULL)pathSum(root->left, targetSum);
		if (root != NULL && root->right != NULL)pathSum(root->right, targetSum);
		return ans;
	}
};