// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        res.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        res.insert( res.end(), left.begin(), left.end() );
        vector<int> right = preorderTraversal(root->right);
        res.insert( res.end(), right.begin(), right.end() );
        return res;
    }
};