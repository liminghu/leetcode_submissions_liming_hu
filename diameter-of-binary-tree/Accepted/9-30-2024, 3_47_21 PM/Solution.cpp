// https://leetcode.com/problems/diameter-of-binary-tree

/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right==NULL)
            return 0;

        if(root->left == NULL) {
            return max( diameterOfBinaryTree(root->right), depth(root)-1);
        }
        //left is not null.
        if(root->right == NULL) {
            return max( diameterOfBinaryTree(root->left), depth(root)-1);
        }
        ////left is not null. right is not null.
        int diameter = 0;
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        diameter = leftDepth-1 + rightDepth-1 + 2; //if pass root.
        return max( max(diameter, diameterOfBinaryTree(root->left)), diameterOfBinaryTree(root->right));
    }
    int depth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right==NULL)
            return 1;
        return max(depth(root->left)+1, depth(root->right)+1);        
    }
};