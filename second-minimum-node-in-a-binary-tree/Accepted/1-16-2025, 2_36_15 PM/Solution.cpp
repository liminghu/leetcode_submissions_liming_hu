// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    int findSecondMinimumValue(TreeNode* root) {
        //root.val = min(root.left.val, root.right.val)
        if(root==NULL)
            return -1;
        if(root->left == NULL && root->right == NULL)
            return -1;
        int rootVal = root->val;
        int leftVal = root->left->val;
        int rightVal = root->right->val;
        if(rootVal == leftVal) {
            leftVal = findSecondMinimumValue(root->left);
        }
        if(rootVal == rightVal) {
            rightVal = findSecondMinimumValue(root->right);
        }        
        if(leftVal!=-1 && rightVal!=-1)
            return min(leftVal, rightVal);
        if(leftVal!=-1)
            return leftVal;
        if(rightVal!=-1)
            return rightVal;
        return -1;
    }
};