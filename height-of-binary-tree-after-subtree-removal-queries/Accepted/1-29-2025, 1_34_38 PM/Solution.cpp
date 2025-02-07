// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries

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
    int preh[100001], posth[100001];
    int maxHeight = 0;

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxHeight = 0;
        pre(root, 0);
        maxHeight = 0;
        post(root, 0);
        vector<int> res;
        for(int q: queries) {
            res.push_back( max(preh[q], posth[q]) );
        }
        return res;
    }
    void pre(TreeNode* root, int h) { //Pre-order dfs the tree (node, left, right),
        if(!root)
            return;
        preh[root->val] = maxHeight;
        maxHeight = max(maxHeight, h);
        pre(root->left, h+1);
        pre(root->right, h+1);
    }
    void post(TreeNode* root, int h) { //ost-order dfs the tree (node, right, left),
        if(!root)
            return;
        posth[root->val] = maxHeight;
        maxHeight = max(maxHeight, h);
        post(root->right, h+1);
        post(root->left, h+1);
    }
};
