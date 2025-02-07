// https://leetcode.com/problems/deepest-leaves-sum

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
    int depth(TreeNode *root) {
        int ans =0;
        if(root == NULL)
            return ans;
        int depthLeft = depth(root->left);
        int depthRight = depth(root->right);
        if(depthLeft > depthRight)
            return depthLeft+1;
        else
            return depthRight+1;
        
    }
    
    int deepestLeavesSum(TreeNode* root) {  //dfs
        int ans = 0;
        //edge cases.
        if(root == NULL) 
            return ans;
        if(root->left == NULL & root->right==NULL)
            return root->val;
        else if(root->left == NULL) {
            return deepestLeavesSum(root->right);
        } if(root->right==NULL) {
            return deepestLeavesSum(root->left);            
        }
        
        int depthLeft = depth(root->left);
        int depthRight = depth(root->right);
        
        if(depthLeft== depthRight) {
            int deepestLeavesSumLeft = deepestLeavesSum(root->left);
            int deepestLeavesSumRight = deepestLeavesSum(root->right);
            ans = deepestLeavesSumLeft + deepestLeavesSumRight;
            return ans;
        } else if(depthLeft>depthRight) {
            int deepestLeavesSumLeft = deepestLeavesSum(root->left);
            return deepestLeavesSumLeft;
        } else {
            int deepestLeavesSumRight = deepestLeavesSum(root->right);
            return deepestLeavesSumRight;
        }
            
        
    }
};