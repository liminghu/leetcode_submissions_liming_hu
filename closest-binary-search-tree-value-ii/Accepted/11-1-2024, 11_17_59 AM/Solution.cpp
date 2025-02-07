// https://leetcode.com/problems/closest-binary-search-tree-value-ii

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res; //ascending...
        helper(res, root, target, k);
       
        return res;
    }
    void helper(vector<int>& res, TreeNode* root, double target, int k) { //inorder
        if( root == NULL )
            return;
        helper(res, root->left, target, k);
        if(res.size() == k) {
            if( abs(target - root->val) < abs(target-res[0]) ) {
                res.erase(res.begin());
            } else
                return;
        }
        res.push_back(root->val);
        helper(res, root->right, target, k);
    }
};