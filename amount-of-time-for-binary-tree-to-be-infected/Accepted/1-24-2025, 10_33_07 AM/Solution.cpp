// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

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
unordered_map<int, vector<int>> graph;
public:
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root);
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        int ret = -1;
        while(!q.empty()) {
            ret++;
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                int cur = q.front();
                q.pop();
                visited.insert(cur);
                for(int neighbor: graph[cur]) {
                    if(!visited.count(neighbor))
                        q.push(neighbor);
                }
            }
        }
        return ret;
    }
    void buildGraph(TreeNode* root) {
        if(root==NULL)
            return;
        if(root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }      
        buildGraph(root->left);
        buildGraph(root->right);  
    }
};