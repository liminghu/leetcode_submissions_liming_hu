// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/
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
    unordered_map<int, int> sum_level; //level, sum
    int maxLevelSum(TreeNode* root) {
        helper(root, 0); //level;
        
        int max_sum = INT_MIN;
        int level = INT_MAX;
        for(auto sum_i: sum_level) {
            if(sum_i.second > max_sum) {
                max_sum = sum_i.second;
                level = sum_i.first;
            } else if(sum_i.second == max_sum && sum_i.first < level) {
                level = sum_i.first;
            };
        }
        return level+1;
    }
    void helper(TreeNode* root, int level) {
        if(root == NULL)
            return;       
        sum_level[level] += root->val;
        helper(root->left, level+1);
        helper(root->right, level+1);
    }
};