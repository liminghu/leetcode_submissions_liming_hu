// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has 
both p and q as descendants (where we allow a node to be a descendant of itself).”
Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
*/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { //left is smaller.
        if(p == NULL) 
            return NULL;
        if(q==NULL)
            return NULL;
            //p, q not NULL
        if(p == root || q == root )
            return root;

        if( p->val > q->val)
            return lowestCommonAncestor(root, q, p);

        if( (p->val < root->val) && (root->val < q->val) )
            return root;
        else if((p->val < root->val) && (q->val < root->val))
            return lowestCommonAncestor(root->left, p, q); 
        else if((p->val > root->val) && (q->val > root->val))  
            return lowestCommonAncestor(root->right, p, q);    
        
        return NULL;
    }
};