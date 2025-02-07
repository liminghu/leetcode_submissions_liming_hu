// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int sz = q.size();
            int start = q.front().second;
            int end = q.back().second;
            res = max(res, end-start+1);
            for(int i=0; i<sz; i++) {
                pair<TreeNode*, int> cur = q.front();
                q.pop();
                int idx = cur.second - start;
                if(cur.first->left!=NULL) 
                    q.push({cur.first->left, 2*idx+1});
               if(cur.first->right!=NULL) 
                    q.push({cur.first->right, 2*idx+2});
            }
        }
        return res;
    }
};