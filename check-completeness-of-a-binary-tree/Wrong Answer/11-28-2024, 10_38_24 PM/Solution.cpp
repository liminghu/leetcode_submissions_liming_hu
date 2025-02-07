// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        if(root->left == NULL && root->right !=NULL)
            return false;
        if(root->left != NULL) {
            if(isCompleteTree(root->left))
                return isCompleteTree(root->right);
            else
                return false;
        }
        return false;
    }
};