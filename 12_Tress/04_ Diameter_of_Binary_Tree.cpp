// 04_ Diameter_of_Binary_Tree.cpp

class Solution {
public:
	int fn(TreeNode* root, int& daimeter) {
		if (!root) return 0;
		int L = fn(root->left, daimeter);
		int R = fn(root->right, daimeter);
		daimeter = max(daimeter, L + R);
		return 1 + max(L, R);
	}

	int diameterOfBinaryTree(TreeNode* root) {
		int daimeter = 0;
		fn(root, daimeter);
		return daimeter;
	}
};
