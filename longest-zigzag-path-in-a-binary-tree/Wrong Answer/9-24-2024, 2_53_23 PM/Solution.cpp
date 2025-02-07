// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

/*
You are given the root of a binary tree.
A ZigZag path for a binary tree is defined as follow:
Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
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
    int longestZigZag(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root && root->left == NULL && root->right == NULL)
            return 0;
        int leftMax = maxZigZag(root, -1); // -1: left
        int rightMax = maxZigZag(root, 1); //1: right.

        return max(leftMax, rightMax);
    }
    int maxZigZag(TreeNode* root, int direction) { //direction: -1: left, 1: right.
        if(root==NULL)
            return 0;
        if(root && root->left == NULL && root->right == NULL)
            return 0;
        
        int ret = 0;
        if(direction == -1 ) { //left
           if( root->left != NULL)
                ret = max( maxZigZag(root->left, 1) + 1, maxZigZag(root->left, -1) );
            else
                ret = 0;
        } else { //right : 1
            if( root->right != NULL)
                ret = max( maxZigZag(root->right, -1) + 1, maxZigZag(root->right, 1) );
            else
                ret = 0;
        }
        return ret;
    }
};