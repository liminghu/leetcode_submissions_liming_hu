// https://leetcode.com/problems/range-sum-of-bst

/*
Given the root node of a binary search tree and two integers low and high, return the sum of 
values of all nodes with a value in the inclusive range [low, high].
The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root == NULL)
            return 0;
        if(low > high)
            return 0;

        int res = 0; 
        if(root->val >= low && root->val <= high)
            res = root->val;
        if(low <= root->val || high <= root->val)
            res += rangeSumBST(root->left, low, high);
        if(root->val <= low || root->val <= high)
            res += rangeSumBST(root->right, low, high);

        return res;
    }
};