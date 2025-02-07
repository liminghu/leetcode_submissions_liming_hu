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
        pair<int, int> ret = helper(root);
        return max(ret.first, ret.second);
    };
    pair<int, int> helper(TreeNode* root) {
        if(root == NULL) {
            return {0, 0};  //{rob this node, not rob this node};
        }
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        //if we rob this node, we can not rob its children.
        int rob = root->val + left.second + right.second;
        //else we free to choose rob its children or not.
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        return {rob, notRob};
    }
};