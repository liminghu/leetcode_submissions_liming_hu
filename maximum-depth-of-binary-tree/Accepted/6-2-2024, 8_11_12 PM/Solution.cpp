// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxDepth(TreeNode* root) {   //dfs
        int depth = 0;
        if(root==NULL)
            return depth;
        if(root->left == NULL)
            return maxDepth(root->right)+1;
        if(root->right == NULL)
            return maxDepth(root->left)+1;
        
        int d_left = maxDepth(root->left);
        int d_right = maxDepth(root->right);

        if(d_left>d_right)
            return d_left+1;
        else
            return d_right+1;

        
    }
};