// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' 
values. (i.e., from left to right, level by level from leaf to root).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
            return {};
        
        stack<int> st;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()) {
            st.push(INT_MIN); //push a row split.
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                st.push(cur->val);
                if(cur->right)
                    q.push(cur->right);
                if(cur->left)
                    q.push(cur->left);
            }
        };
        vector<int> curRow;
        while(!st.empty()) {
            int t = st.top();
            //cout << "stack top: " << t << endl;
            st.pop();
            if(t == INT_MIN) {
                if(curRow.size()>0) {
                    ans.push_back(curRow);
                    curRow.clear();
                }
            }
            else
                curRow.push_back(t);
        };
        return ans;
    }
};