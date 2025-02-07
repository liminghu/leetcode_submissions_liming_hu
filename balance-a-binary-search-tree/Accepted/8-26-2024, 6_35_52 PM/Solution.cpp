// https://leetcode.com/problems/balance-a-binary-search-tree

/*Given the root of a binary search tree, return a balanced binary search tree with the same node values.
 If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1
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
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr)
            return root;
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int n = inorder.size();
        return buildBalancedBST(inorder, 0, n-1);

    }

    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(root == nullptr)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* buildBalancedBST(const vector<int>& inorder, int start, int end) {
        if(start>end) 
            return nullptr;
        
        int mid = start+(end-start)/2;
        TreeNode* left = buildBalancedBST(inorder, start, mid-1);
        TreeNode* right = buildBalancedBST(inorder, mid+1, end); 
        return new TreeNode(inorder[mid], left, right);        
    }
};