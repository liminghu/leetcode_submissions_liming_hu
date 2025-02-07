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
        if(root==nullptr || root->left==nullptr && root->right == nullptr)
            return 0;
        int ans=0;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if(left!=nullptr) {
            if(left->left == nullptr && left->right == nullptr)
                ans+=left->val;
        };
        
        ans+= sumOfLeftLeaves(right);
        
        return ans;
        
    }
};