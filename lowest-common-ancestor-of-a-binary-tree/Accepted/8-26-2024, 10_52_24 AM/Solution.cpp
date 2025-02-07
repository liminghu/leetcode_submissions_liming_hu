// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

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
        /*  The number of nodes in the tree is in the range [2, 105].
            -109 <= Node.val <= 109
            All Node.val are unique.
            p != q
            p and q will exist in the tree.
        */
        if(root == NULL)
            return root;
        if(root == p)
            return p;
        if(root == q)
            return q;
        
        TreeNode *leftAnce = lowestCommonAncestor(root->left, p, q);       
        TreeNode *rightAnce = lowestCommonAncestor(root->right, p, q);
        if( leftAnce != NULL && rightAnce != NULL )
            return root;
        
        if(leftAnce != NULL)
            return leftAnce;
        else 
            return rightAnce;
    }
};