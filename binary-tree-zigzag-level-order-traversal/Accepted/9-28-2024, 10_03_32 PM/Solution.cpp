// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        bool left_right = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> cur_ans;
            for(int i=0; i<size; i++) {
                if(left_right) {
                    TreeNode* cur = q.front();
                    cur_ans.push_back(cur->val);
                    q.pop_front();
                    if(cur->left)
                        q.push_back(cur->left);
                    if(cur->right)
                        q.push_back(cur->right);
                } else {
                   TreeNode* cur = q.back();
                    cur_ans.push_back(cur->val);
                    q.pop_back();
                    if(cur->right)
                        q.push_front(cur->right);    
                    if(cur->left)
                        q.push_front(cur->left);                
                }
            }
            ans.push_back(cur_ans);
            left_right = !left_right;
        }
        return ans;
    }
};