// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        dfs(root, freq);
        int maxFreq = 0;
        for(auto&[key, val]: freq) {
            maxFreq = max(maxFreq, val);
        }
        vector<int> rets;
        for(auto&[key, val]: freq) {
            if(val == maxFreq)
            rets.push_back(key);
        }
        return rets;
    }
    void dfs(TreeNode* root, unordered_map<int, int>& freq) {
        if(root==NULL)
            return;
        freq[root->val]++;
        dfs(root->left, freq);
        dfs(root->right, freq);
    }
};