// 235_LCA_BST.cpp

// jaha ek node left aur ek node right mai jayegii vhi split hoga so vhi lca hoga
// also equal valle case ke liye mai bhi yhi hoga hum decide nhi kar payenge jis node
// pe vhi lca hoga
// tc == o(h) & o(1) not considering the stack space
// if we use the while loop then no space complexity


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);
		if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);
		return root;
	}

};