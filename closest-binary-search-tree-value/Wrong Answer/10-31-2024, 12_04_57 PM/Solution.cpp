// https://leetcode.com/problems/closest-binary-search-tree-value

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
    int closestValue(TreeNode* root, double target) {
        int cur = INT_MAX;
        closestValue(root, target, cur);
        return cur;
    }
    int closestValue(TreeNode* root, double target, int& cur) {
        if(root == NULL) 
            return cur;
        double diff = abs(root->val - target);
        if(root->left == NULL && root->right == NULL) {
            cout << "diff: " << diff << endl;
            cout << "cur: " << cur << endl;
            if(diff < abs(cur-target) ) {
                cur = root->val;
                return cur;
            } 
        }
        if(target >= root->val) {
            if (diff < abs( target-closestValue(root->right, target, cur) ) ) {
                cur = root->val;
            };
        } else {
            if (diff < abs (target - closestValue(root->left, target, cur) ) ) {
                cur = root->val;
            };           
        };
        return cur;
    } 
};