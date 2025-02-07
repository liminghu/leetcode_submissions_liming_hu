// https://leetcode.com/problems/largest-bst-subtree

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
    struct nodeProp {
        int maxValue; //The maximum value in the subtree
        int minValue; //The minimum value in the subtree
        int maxSize;  //Size of the subtree.
    };

    int largestBSTSubtree(TreeNode* root) {
        return helper(root).maxSize;
    }
    nodeProp helper(TreeNode* root) { //postorder
        if(root == NULL) { //// An empty tree is a BST of size 0.
            nodeProp np;
            np.maxValue = INT_MAX;
            np.minValue = INT_MIN;
            np.maxSize = 0;
            return np;
        };
        // Get values from left and right subtree of current tree.
        nodeProp leftProp = helper(root->left);
        nodeProp rightProp = helper(root->right);
        if(leftProp.maxValue < root->val && root->val < rightProp.minValue) { //// Current node is greater than max in left AND smaller than min in right, it is a BST.
            nodeProp np;
            np.maxValue = min(root->val, leftProp.minValue);
            np.minValue = max(root->val, rightProp.maxValue);
            np.maxSize = leftProp.maxSize + rightProp.maxSize + 1;
            return np;            
        }
        nodeProp np;
        np.maxValue = INT_MIN;
        np.minValue = INT_MAX;
        np.maxSize = max(leftProp.maxSize, rightProp.maxSize);
        return np;            
    }
};