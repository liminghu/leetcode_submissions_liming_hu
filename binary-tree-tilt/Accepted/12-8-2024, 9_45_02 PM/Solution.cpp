// https://leetcode.com/problems/binary-tree-tilt

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
    int tiltSum = 0;
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return tiltSum;
    }
    int dfs(TreeNode* root) { //tree sum.
        if(root==NULL)
            return 0;
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        tiltSum += abs(leftSum-rightSum);
        return leftSum + rightSum + root->val;
    }
};