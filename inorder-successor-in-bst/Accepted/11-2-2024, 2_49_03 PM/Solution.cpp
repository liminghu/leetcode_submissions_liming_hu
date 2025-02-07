// https://leetcode.com/problems/inorder-successor-in-bst

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candidate = NULL;
        while(root) { //search from root to bottom, trying to find the smallest node larger than p and return the last one that was larger.
            if(root->val > p->val) {
                candidate = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return candidate;
    }
};