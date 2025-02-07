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
        leftFirst(root, 0);
        maxHeight = 0;
        rightFirst(root, 0);
        vector<int> res;
        for(int q: queries) {
            res.push_back( max(preh[q], posth[q]) );
        }
        return res;
    }
    void leftFirst(TreeNode* root, int h) { //Pre-order dfs the tree (node, left, right),
        if(!root)
            return;
        preh[root->val] = maxHeight;
        maxHeight = max(maxHeight, h);
        leftFirst(root->left, h+1);
        leftFirst(root->right, h+1);
    }
    void rightFirst (TreeNode* root, int h) { //ost-order dfs the tree (node, right, left),
        if(!root)
            return;
        posth[root->val] = maxHeight;
        maxHeight = max(maxHeight, h);
        rightFirst (root->right, h+1);
        rightFirst (root->left, h+1);
    }
};
