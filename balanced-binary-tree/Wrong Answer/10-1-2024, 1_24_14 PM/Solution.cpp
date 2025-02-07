// https://leetcode.com/problems/balanced-binary-tree

//Given a binary tree, determine if it is height-balanced.
/*
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        int l_height = height(root->left);
        int r_height = height(root->right);
        cout << "left height:" << l_height << endl;
        cout << "right height:" << r_height << endl;        
        return abs( l_height - r_height ) <= 1;
    }
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1; 
        int l_height = height(root->left);
        int r_height = height(root->right);   
        return max(l_height, r_height) + 1;      
    }
};