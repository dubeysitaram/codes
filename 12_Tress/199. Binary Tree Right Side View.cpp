// 199. Binary Tree Right Side View.cpp
/*
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.



Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

*/

class Solution {
public:
	vector<int> fans;
	void fn(TreeNode* root, int level) {
		if (root == NULL)
			return;
		if (fans.size() == level) {
			fans.push_back(root->val);
		}
		fn(root->right, level + 1);
		fn(root->left, level + 1);
	}
	vector<int> rightSideView(TreeNode* root) {
		if (root == NULL)
			return {};
		if (root->left == NULL && root->right == NULL)
			return {root->val};
		fn(root, 0);
		return fans;
	}
};