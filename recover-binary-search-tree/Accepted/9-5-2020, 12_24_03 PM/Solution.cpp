// https://leetcode.com/problems/recover-binary-search-tree

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
  void recoverTree(TreeNode *root) { 
		inorder(root);
		swap(first->val, second->val);
  }
 
private:
	TreeNode* first;
	TreeNode* second;
	TreeNode* prev_;
	
	void inorder(TreeNode *root) {
		if(!root) return;
		inorder(root->left);
		if(prev_ && prev_->val > root->val) {
			if(!first) 
				first = prev_;
			second = root;
		}
		prev_ = root;
		inorder(root->right);	
	}
};