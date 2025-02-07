// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return dfs(root, st, k);
    }
    bool dfs(TreeNode* root, unordered_set<int>& st, int k ) {
        if(root==NULL)
            return false;
        if(st.count(k-root->val))
            return true;
        st.insert(root->val);
        return dfs(root->left, st, k) || dfs(root->right, st, k); 
    }
};