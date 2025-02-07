// https://leetcode.com/problems/binary-tree-maximum-path-sum

/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an 
edge connecting them. A node can only appear in the sequence at most once. Note that the path does not 
need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left== NULL && root->right == NULL)
            return root->val;
        int left  = maxPathSum(root->left);
        int right = maxPathSum(root->right);
        int res = INT_MIN;
        res = max( res, left );
        res = max( res, left+root->val);
        res = max( res, left+root->val+right );
        res = max( res, root->val);
        res = max( res, root->val+right);
        res = max( res, right);
        return res;
    }
};