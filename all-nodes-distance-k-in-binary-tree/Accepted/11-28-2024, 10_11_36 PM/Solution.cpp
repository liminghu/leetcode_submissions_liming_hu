// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> parent; //son->parent
    unordered_set<TreeNode*> visited;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)
            return {};
        findParent(root);
        dfs(target, k);
        return ans;
    }
    void findParent(TreeNode* root) {
        if(root == NULL)
            return;
        if(root->left) {
            parent[root->left] = root;
            findParent(root->left);
        }
        if(root->right) {
            parent[root->right] = root;
            findParent(root->right);
        }
    }
    void dfs(TreeNode* node, int k) {
        if(visited.find(node) != visited.end())
            return;
        visited.insert(node);
        if(k==0) {
            ans.push_back(node->val);
            return;
        }
        if(node->left) 
            dfs(node->left, k-1);
        
        if(node->right)
            dfs(node->right, k-1);
        TreeNode* p = parent[node];
        if(p)
            dfs(p, k-1);
    }
};