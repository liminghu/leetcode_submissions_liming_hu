// https://leetcode.com/problems/average-of-levels-in-binary-tree

/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;
            for(int i=0; i<size; i++) {
                TreeNode* item = q.front();
                q.pop();
                sum += item->val;
                if(item->left)
                    q.push(item->left);
                if(item->right)
                    q.push(item->right);
            };
            ans.push_back((sum*1.0)/size);
        }; 
        return ans;       
    }
};