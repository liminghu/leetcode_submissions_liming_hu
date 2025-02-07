// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {        
        if(root==nullptr) return {};
               
        /*
        vector<int> left = postorderTraversal(root->left);
        res.insert( res.end(), left.begin(), left.end() );
        vector<int> right = postorderTraversal(root->right);
        res.insert( res.end(), right.begin(), right.end() );
        res.push_back(root->val); 
        */
        
        stack<TreeNode*> st;
		deque<int> ans;
        st.push(root);
        while (!st.empty()) {
            TreeNode *n = st.top();
            st.pop();
            
            ans.push_front(n->val);  //O(1)
            

            if (n->left!=nullptr) 
                st.push(n->left);
            if(n->right!=nullptr) 
                st.push(n->right);

        }
        return vector<int>(ans.begin(), ans.end());        
    }
};