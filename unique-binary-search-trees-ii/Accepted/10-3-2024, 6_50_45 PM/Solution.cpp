// https://leetcode.com/problems/unique-binary-search-trees-ii

/*Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly 
n nodes of unique values from 1 to n. Return the answer in any order.
Constraints:
1 <= n <= 8
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {NULL};
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end) {
        if(start>end) {
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> leftNodes = helper(start, i-1);
            vector<TreeNode*> rightNodes = helper(i+1, end);

            for(TreeNode* left: leftNodes) {
                for(TreeNode* right: rightNodes) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};