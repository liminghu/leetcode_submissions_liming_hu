// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        int dx = -1;
        TreeNode* px;
        int dy = -1;
        TreeNode* py;
        px = findParentdepth(root, x, 0, dx);

        py = findParentdepth(root, y, 0, dy);
        return dx == dy && px != py;        
    }
    TreeNode* findParentdepth(TreeNode* root, int x, int depth, int& dx) {
        if(root== NULL)
            return NULL;
        if((root->left && root->left->val == x) || (root->right && root->right->val == x) ) {
            dx = depth;
            return root;
        }
        TreeNode* left = findParentdepth(root->left, x, depth+1, dx);
        if(left) 
            return left;

        TreeNode* right = findParentdepth(root->right, x, depth+1, dx);
        if(right)
            return right;
        return NULL;
    }
};