// https://leetcode.com/problems/boundary-of-binary-tree

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
private:
    vector<int> rets;
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root->left ==NULL && root->right == NULL) {
            rets.push_back(root->val);
            return rets;
        }
        rets.push_back(root->val);
        getLeft(root->left);
        getBottom(root);
        getRight(root->right);
        return rets;
    }
    void getLeft(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;
        rets.push_back(root->val);
        if(root->left !=NULL)
            getLeft(root->left);
        else
            getLeft(root->right);
    }
    void getBottom(TreeNode* root) {
        if(root==NULL)
            return;
        if(root->left == NULL && root->right==NULL) {
            rets.push_back(root->val);
            return;
        }
        getBottom(root->left);
        getBottom(root->right);
    }
    void getRight(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;
        if(root->right !=NULL)
            getRight(root->right);
        else
            getRight(root->left);    
        rets.push_back(root->val);            
    }
};