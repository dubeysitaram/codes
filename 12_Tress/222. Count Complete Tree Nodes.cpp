// 222. Count Complete Tree Nodes.cpp
/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree,
 and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

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
	void inorder(TreeNode* root, int& ct) {
		if (root == NULL) {
			return;
		}
		ct++;
		inorder(root->left, ct);
		inorder(root->right, ct);
	}
	int leftHeight(TreeNode* root) {
		if (root == NULL)
			return 0;
		return 1 + leftHeight(root->left);
	}
	int rightHeight(TreeNode* root) {
		if (root == NULL)
			return 0;
		return 1 + rightHeight(root->right);
	}

	int numofnodes2(TreeNode* root) {
		int ans = 0;
		int lefth = leftHeight(root);
		int righth = rightHeight(root);
		if (lefth == righth)
			return pow(2, lefth) - 1;
		ans += numofnodes2(root->left);
		ans += numofnodes2(root->right);
		return ans + 1;
	}

	int countNodes(TreeNode* root) {
		// int ct = 0;
		// inorder(root, ct);// method 1
		// return ct;
		return numofnodes2(root);
	}
};
// be aware the tree is complete means bich mai nodes gayab nhi hoge tree ke
// tc = o((logn)^2) and space complexity = o(h);


// if both the left height and right height are equal at a given node then we will simmply return the 2^h-1;
// else we will add 1 for current node and return 1+numnodes(node->left)+numnodes(node->right);