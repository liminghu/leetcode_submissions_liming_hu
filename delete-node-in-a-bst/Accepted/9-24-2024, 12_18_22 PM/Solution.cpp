// https://leetcode.com/problems/delete-node-in-a-bst

/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
Constraints:
The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //find node
        TreeNode* node = findNode(root, key);
        TreeNode* newroot;
        if(node) { // //delete node
            newroot = deletenode(root, node);
            return newroot;
        } else 
            return root;
    }
    TreeNode* findNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(root->val ==key)
            return root;
        if(root->val < key)
            return findNode(root->right, key);
        else
            return findNode(root->left, key);
    }

    TreeNode* deletenode(TreeNode* root, TreeNode* node) {
        if(root->val == node->val) {
            //delete root
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* newroot = right;
            if(right==NULL)
                return left;
            while(right && right->left) {
                right = right->left;
            };
            right->left = left;
            return newroot;
        } else if(root->val < node->val) {
            TreeNode* right = deletenode(root->right, node);
            root->right = right;
        } else {
            TreeNode* left = deletenode(root->left, node);
            root->left = left;
        }
        return root;
    }
};