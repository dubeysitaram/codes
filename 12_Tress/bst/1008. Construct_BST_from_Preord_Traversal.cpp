// 1008. Construct_BST_from_Preord_Traversal.cpp
/*
Given an array of integers preorder, which represents the preorder traversal of a BST
(i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree
with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.
left has a value strictly less than Node.val, and any descendant of Node.
right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first,
then traverses Node.left, then traverses Node.right.

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

*/

class Solution {
public:
	TreeNode* buildtree(vector<int>& preorder, int& currind, int upperlimit) {
		if (currind >= preorder.size() || preorder[currind] > upperlimit)
			return NULL;

		TreeNode* node = new TreeNode(preorder[currind]);
		currind++;
		TreeNode* left = buildtree(preorder, currind, node->val); // upperlimit changes for left part
		TreeNode* right = buildtree(preorder, currind, upperlimit); // upper limit same as that of  previous of the parent node
		node->left = left;
		node->right = right;
		return node;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int currind = 0;
		int upperlimit = INT_MAX;
		return buildtree(preorder, currind, upperlimit);
	}
};


class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int ind = 0, n = preorder.size();
		TreeNode* root = new TreeNode(preorder[ind]);
		ind++;
		while (ind < n) {
			TreeNode* temp = root;
			while (true) {
				if (temp->left == NULL && temp->right == NULL)
					break;
				if (temp->val < preorder[ind]) {
					if (temp->right == NULL)break;
					temp = temp->right;
				} else {
					if (temp->left == NULL)break;
					temp = temp->left;
				}
			}
			if (temp->val < preorder[ind]) {
				temp->right = new TreeNode(preorder[ind]);
			} else {
				temp->left = new TreeNode(preorder[ind]);
			}
			ind++;
		}
		return root;
	}
};
