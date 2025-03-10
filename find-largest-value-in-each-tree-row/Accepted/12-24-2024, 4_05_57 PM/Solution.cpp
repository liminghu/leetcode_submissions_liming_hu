// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> rets = {};
        if(root==NULL)
            return rets;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int maxVal = INT_MIN;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                maxVal = max(maxVal, cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            rets.push_back(maxVal);
        }
        return rets;
    }
};