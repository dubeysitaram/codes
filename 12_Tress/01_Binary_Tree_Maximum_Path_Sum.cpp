/*
124. Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
in the sequence has an edge connecting them. A node can only appear in the sequence at most once.
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

class Solution {
public:
    int maxpathsum(TreeNode* root, int& pathsum) {
        if (root == NULL)return 0;
        int leftsum = max(0, maxpathsum(root->left, pathsum));
        int rightsum = max(0, maxpathsum(root->right, pathsum));
        pathsum = max(pathsum, root->val + leftsum + rightsum);
        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int pathsum = INT_MIN;
        maxpathsum(root, pathsum);
        return pathsum;
    }
};