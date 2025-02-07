// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)
            return root;
        if(root->left == NULL && root->right == NULL)
            return root;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> curLevelNodes;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curLevelNodes.push_back(cur);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(level%2==1) {
                int left = 0;
                int right = curLevelNodes.size()-1;
                while(left<right) {
                    int temp = curLevelNodes[left]->val;
                    curLevelNodes[left]->val = curLevelNodes[right]->val;
                    curLevelNodes[right]->val = temp;
                    left++;
                    right--;
                };
            };
            level++;
        }
        return root;
    }
};