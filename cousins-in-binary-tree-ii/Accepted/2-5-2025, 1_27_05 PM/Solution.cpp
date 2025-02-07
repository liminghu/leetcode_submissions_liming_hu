// https://leetcode.com/problems/cousins-in-binary-tree-ii

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        //Two nodes of a binary tree are cousins if they have the same depth with different parents.
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;
            vector<TreeNode*> buf;
            while(sz--) {
                TreeNode* cur = q.front();
                q.pop();
                buf.push_back(cur);
                if(cur->left) {
                    q.push(cur->left);
                    sum += cur->left->val; 
                };
               if(cur->right) {
                    q.push(cur->right);
                    sum += cur->right->val; 
                };                
            }
            for(auto node:buf) {
                int t = sum;
                if(node->left)
                    t -= node->left->val;
                if(node->right)
                    t-=node->right->val;
                if(node->left)
                    node->left->val = t;
                if(node->right)
                    node->right->val = t;                    
            }
        }
        return root;
    }
};