// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return {};
        if(root->left == NULL && root->right == NULL)
            return {to_string(root->val)};
        vector<string> leftPath;
        if(root->left) 
            leftPath = binaryTreePaths(root->left);
        vector<string> rets;
        for(int i=0; i<leftPath.size(); i++) {
            string path_i = leftPath[i];
            string path = to_string(root->val) + "->";
            path = path + path_i;
            rets.push_back(path);
        }
        vector<string> rightPath;
         if(root->right) 
            rightPath = binaryTreePaths(root->right);
        for(int i=0; i<rightPath.size(); i++) {
            string path_i = rightPath[i];
            string path = to_string(root->val) + "->";
            path = path + path_i;
            rets.push_back(path);
        };
        return rets;
    }
};