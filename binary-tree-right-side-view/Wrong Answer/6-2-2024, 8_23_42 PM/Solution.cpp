// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {  //bfs
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
        q.push(root);
        TreeNode* cur;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            ans.push_back(cur->val);
            if(cur->right == NULL && cur->left!=NULL)
                q.push(cur->left);
            else if(cur->right != NULL) 
                q.push(cur->right);
        };
        
        return ans;
    }
};