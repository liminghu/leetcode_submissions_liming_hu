// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
		if(root == nullptr) return res;
		queue<TreeNode*> q; //using only one queue / use a marker NULL
		q.push(root);
		q.push(NULL);
		vector<int> level_vec;
		while( !q.empty() ) {
			TreeNode* t = q.front();
			q.pop();
			if(t==NULL)  { // to the end of one level.
				res.push_back(level_vec);
				level_vec.resize(0);
				if(q.size()>0) {
					q.push(NULL);
				};
            } else {
				level_vec.push_back(t->val);
				if(t->left) q.push(t->left); //Insert element
				if(t->right) q.push(t->right);
			}
		}
		return res;
    }
};