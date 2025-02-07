// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
private:
    int res = 1;
public:
    int longestConsecutive(TreeNode* root) { //Given the root of a binary tree, return the length of the longest consecutive sequence path.
                                             //A consecutive sequence path is a path where the values increase by one along the path.
        if(root == NULL)
            return 0;
        helper(root, root->val, 0);
        return res;
    }
    void helper(TreeNode* root, int curr, int count) {
        if(root==NULL)
            return;
        if(root->val == curr) {
            count++;
            res = max(res, count);
            helper(root->left, curr+1, count);
            helper(root->right, curr+1, count);
        } else {
            helper(root->left, root->val+1, 1);
            helper(root->right, root->val+1, 1);            
        }
    }
};