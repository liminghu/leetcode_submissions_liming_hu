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
class nodeProp {
public:
    int minValue; //The minimum value in the subtree
    int maxValue; //The maximum value in the subtree
    int maxSize;  //max Size of the BST subtree.
    nodeProp(int minValue, int maxValue, int maxSize) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).maxSize;
    }
    //By traversing each tree's children first, we can pass information about subtrees up to the parent. This information can be used by the parent to determine if the parent node is a BST in constant time.
    nodeProp helper(TreeNode* root) { //postorder
        if(root == NULL) { //// An empty tree is a BST of size 0.
            return nodeProp(INT_MAX, INT_MIN, 0);
        };
        // Get values from left and right subtree of current tree.
        nodeProp leftProp = helper(root->left);
        nodeProp rightProp = helper(root->right);
        if(leftProp.maxValue < root->val && root->val < rightProp.minValue) { //// Current node is greater than max in left AND smaller than min in right, it is a BST.
            return nodeProp(min(root->val, leftProp.minValue), 
                            max(root->val, rightProp.maxValue),
                            leftProp.maxSize + rightProp.maxSize + 1 );            
        }

        return nodeProp(INT_MIN, INT_MAX,
                        max(leftProp.maxSize, rightProp.maxSize));            
    }
};