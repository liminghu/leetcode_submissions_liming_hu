// https://leetcode.com/problems/count-good-nodes-in-binary-tree

/*
Given a binary tree root, a node X in the tree is named good if 
in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.
The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
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
    int goodNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root && root->left == NULL && root->right == NULL)
            return 1;
        return helper(root, root->val);
    }
    int helper(TreeNode* root, int minVal) {
        if(root == NULL)
            return 0;

        int ret = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(root->val >= minVal)
            ret++;
            if(left) 
                ret += helper(left, max(left->val, minVal));
            if(right) 
                ret += helper(right, max(right->val, minVal));
        return ret; 
    }
};