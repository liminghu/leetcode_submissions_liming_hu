// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = LCA(root, p, q);
        if(ans == p) 
            return dfs(p,q)? p:NULL;
        else if(ans == q)
            return dfs(q,p)? q:NULL;
        return ans;
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root == p || root == q)
            return root;
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);  
        if(left && right)
            return root;
        else if(left)
            return left;
        else
            return right;      
    }

    bool dfs(TreeNode* node, TreeNode* target) {
        if(node == target)
            return true;
        if(node == NULL)
            return false;
        return dfs(node->left, target) || dfs(node->right, target);
    }
};