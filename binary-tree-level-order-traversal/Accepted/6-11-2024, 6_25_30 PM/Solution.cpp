// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //queue
        queue<TreeNode*> q_level;
        vector<vector<int>> ans= {};
        if(root == nullptr) 
            return ans;
        vector<int> level_result;
        q_level.push(root);
        while(!q_level.empty()) {
            int sz = q_level.size();
            while(sz--) {
                TreeNode* cur = q_level.front(); q_level.pop();
                level_result.push_back(cur->val);
                if(cur->left) q_level.push(cur->left);
                if(cur->right) q_level.push(cur->right);
            }
            ans.push_back(level_result);
            level_result.clear();

        }
        return ans;
    }
};