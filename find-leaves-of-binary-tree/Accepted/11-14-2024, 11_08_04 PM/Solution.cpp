// https://leetcode.com/problems/find-leaves-of-binary-tree

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
    vector<vector<int>> res;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if(root==NULL) 
            return -1;
        int currHeight = max(dfs(root->left), dfs(root->right)) +1;
        if(currHeight == res.size() ) /// create space for node located at `currHeight` if not already exists
            res.push_back(vector<int>());
        res[currHeight].push_back(root->val);//insert the value at the correct position in the solution array
        return currHeight;
    }
};