// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
		prev_ = nullptr;
		return inorder(root);
	};
private: 
	TreeNode* prev_;
	bool inorder(TreeNode* root) {
		if (root==nullptr) return true;
		if (inorder(root->left) != true ) return false;
		if ( prev_ && root->val <= prev_->val) return false;
		prev_ = root;
		return inorder(root->right);
	}
};