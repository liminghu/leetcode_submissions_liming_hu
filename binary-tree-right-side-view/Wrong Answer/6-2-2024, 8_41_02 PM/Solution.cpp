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
    int depth(TreeNode *root) {
        int ans=0;
        if(root==NULL)
            return 0;
        else if(root->left!=NULL && root->right!=NULL) {
            int d_left = depth(root->left);
            int d_right = depth(root->right);
            if(d_left>d_right)
                return d_left+1;
            else
                return d_right+1;
        } else if(root->left==NULL) {
            int d_right = depth(root->right);
            return d_right+1;
        } else if(root->right==NULL) {
            int d_left = depth(root->left);
            return d_left+1;
        } else 
            return 1;
            
    }
    vector<int> rightSideView(TreeNode* root) {  //bfs
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
        q.push(root);
        TreeNode* cur;
        int layer = 0;
        unordered_map<int, bool> layer_visited;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            layer = depth(cur);
            if(layer_visited.find(layer)==layer_visited.end()) {
                ans.push_back(cur->val);
                layer_visited[layer] = true;
                layer++;
            }
            if(cur->right == NULL && cur->left!=NULL)
                q.push(cur->left);
            else if(cur->right != NULL) 
                q.push(cur->right);
            if(cur->left!=NULL) 
                q.push(cur->left);

        };
        
        return ans;
    }
};