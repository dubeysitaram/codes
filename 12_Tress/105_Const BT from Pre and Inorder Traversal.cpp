// 105_Const BT from Pre and Inorder Traversal.cpp

/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and
inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
	// index in inorder = idx
	// index in preorder = pdx
	unordered_map<int, int> mp;
	TreeNode* construct(int start, int end, int& pdx, vector<int>& preorder, vector<int>& inorder) {
		if (start > end)
			return NULL;

		TreeNode* root = new TreeNode(preorder[pdx]);
		int idx = mp[preorder[pdx]];
		pdx++;

		root->left = construct(start, idx - 1, pdx, preorder, inorder);
		root->right = construct(idx + 1, end, pdx, preorder, inorder);

		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int pdx = 0;

		for (int i = 0; i < inorder.size(); ++i)
			mp[inorder[i]] = i;

		return construct(0, inorder.size() - 1, pdx, preorder, inorder);
	}
};