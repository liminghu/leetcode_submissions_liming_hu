// https://leetcode.com/problems/sum-of-left-leaves

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 0;
        if(root->left) {
            if( isLeaf(root->left) )
                return root->left->val + sumOfLeftLeaves(root->right);
            else
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        } else {
            return sumOfLeftLeaves(root->right);
        }
        
    }
    bool isLeaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }
};