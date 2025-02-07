// https://leetcode.com/problems/invert-binary-tree

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
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == nullptr)
            return nullptr;
        TreeNode* left = root->left;
        if (left != nullptr)  {
            left = invertTree(left);
            
        };
        TreeNode* right = root->right;
        if (right != nullptr)  {
            right = invertTree(right);
            
        };

        if (left != nullptr && right != nullptr) {
            TreeNode* temp;
            temp = left;
            root->left = right;
            root->right = temp; 
        };
        if (left != nullptr && right == nullptr) {
            root->right = left;
            root->left = nullptr;
        }
        if (right != nullptr && left == nullptr) {
            root->left = right;
            root->right = nullptr;
        }

        return root;
    }
};