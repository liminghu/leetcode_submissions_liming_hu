// https://leetcode.com/problems/house-robber-iii

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
    int rob(TreeNode* root) { //level 
        if(root == NULL) 
            return 0;
        int res1 = 0, res2 = 0;
        queue<TreeNode*> q;
        q.push(root);
        bool first_turn = true;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                TreeNode* f = q.front();
                q.pop();
                if(first_turn)
                    res1 += f->val;
                else
                    res2 += f->val;
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            first_turn = !first_turn;
        };
        return max(res1, res2);
    }
};