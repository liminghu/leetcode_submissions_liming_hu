// https://leetcode.com/problems/same-tree

/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
The number of nodes in both trees is in the range [0, 100].
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == NULL)
            return  (q == NULL);
        
        //p is not null
        if(q == NULL)
            return false;
        
        //p q not null
        if(p->val != q->val)
            return false;
        
        //p q have the same val.
         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};