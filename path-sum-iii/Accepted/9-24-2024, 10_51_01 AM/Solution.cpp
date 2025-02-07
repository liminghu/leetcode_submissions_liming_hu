// https://leetcode.com/problems/path-sum-iii

/*
Given the root of a binary tree and an integer targetSum, return the number of paths where 
the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards 
(i.e., traveling only from parent nodes to child nodes).
The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
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
    int ret = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root) {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ret;
    }
    void dfs(TreeNode* root, long long sum) {
        if(root == NULL)
            return;
        if(root->val == sum )
            ret++;
        dfs(root->left,  sum-root->val);
        dfs(root->right, sum-root->val);
    }
};