// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
postorder is the postorder traversal of the same tree, construct and return the binary tree.
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //inorder: left, root, right
        //postorder: left, right, root.
        for(int i=0; i<inorder.size(); i++) 
            mp[ inorder[i] ] = i;
        
        return tree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    };
    TreeNode* tree(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2) {
        if (s1>e1 || s2>e2)
            return NULL;
        TreeNode* node = new TreeNode(postorder[e2]);
        int io_loc = mp[node->val]; //root

        node->left = tree(inorder, s1, io_loc-1, postorder, s2, s2+(io_loc-1-s1) );
        node->right = tree(inorder, io_loc+1, e1, postorder, s2+(io_loc-1-s1)+1,   e2-1);
        return node;
    }
};