// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    int res = INT_MAX;
    int prev_val = INT_MIN;
    int minDiffInBST(TreeNode* root) {
        if(root->left!=NULL)
            minDiffInBST(root->left);
        if(prev_val>=0)
            res = min(res, root->val-prev_val);
        prev_val = root->val;
        if(root->right!=NULL)
            minDiffInBST(root->right);        
        return res;
    }
};