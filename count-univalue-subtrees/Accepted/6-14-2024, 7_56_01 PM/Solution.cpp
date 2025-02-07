// https://leetcode.com/problems/count-univalue-subtrees

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
    bool isUnivalSubtrees(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        if(root->left == nullptr && root->right ==nullptr)
            return true;
        
        if(root->left == nullptr && root->right !=nullptr && root->val == root->right->val && isUnivalSubtrees(root->right))
            return true;
        if(root->left != nullptr && root->right ==nullptr && root->val == root->left->val && isUnivalSubtrees(root->left))
            return true;
        if(root->left != nullptr && root->right !=nullptr && root->val == root->left->val && isUnivalSubtrees(root->left) 
                                                          && root->val == root->right->val && isUnivalSubtrees(root->right))
            return true;
        
        return false;     
        
    }
    
    int countUnivalSubtrees(TreeNode* root) { //A uni-value subtree means all nodes of the subtree have the same value.
        int ans = 0;
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right ==nullptr)
            return 1;
        
        if(root->left == nullptr && root->right !=nullptr && root->val == root->right->val && isUnivalSubtrees(root->right))
            return countUnivalSubtrees(root->right)+1;
        if(root->left != nullptr && root->right ==nullptr && root->val == root->left->val && isUnivalSubtrees(root->left))
            return countUnivalSubtrees(root->left)+1;
        if(root->left != nullptr && root->right !=nullptr && root->val == root->left->val && isUnivalSubtrees(root->left) 
                                                          && root->val == root->right->val && isUnivalSubtrees(root->right))
            return countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right)+1;
        
        return countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right);
        
    }
};