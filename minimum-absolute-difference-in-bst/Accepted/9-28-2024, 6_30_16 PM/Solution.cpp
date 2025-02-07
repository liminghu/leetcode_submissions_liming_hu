// https://leetcode.com/problems/minimum-absolute-difference-in-bst

/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
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
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
            return INT_MAX;
        if(root->left==NULL && root->right==NULL)
            return INT_MAX;
        
        int leftMax = 0;
        int rightmin = 0;
        int res = INT_MAX;
        if(root->left) {
            leftMax = getMax(root->left);
            res = min( res, abs( leftMax - root->val ) );

            res = min( res, getMinimumDifference(root->left) );
        }
        if(root->right) {
            rightmin = getMin(root->right);
            res = min(res, abs(rightmin-root->val));
            res = min(res, getMinimumDifference(root->right));
        };
        return res;
    }
    int getMin(TreeNode* root) {
        if(root->left == NULL)
            return root->val;
        return getMin(root->left);
    };

    int getMax(TreeNode* root) {
        if(root->right == NULL)
            return root->val;
        return getMax(root->right);
    }
};