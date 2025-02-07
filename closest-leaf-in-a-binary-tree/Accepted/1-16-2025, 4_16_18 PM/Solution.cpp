// https://leetcode.com/problems/closest-leaf-in-a-binary-tree

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
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    TreeNode* start = NULL;
    int findClosestLeaf(TreeNode* root, int k) {
        buildGraph(root, NULL, k);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(start);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(!cur->left && !cur->right)
                return cur->val; //first leaf node we find, return it.
            visited.insert(cur);
            for(auto& neighbor:graph[cur]) {
                if(visited.find(neighbor)!=visited.end())
                    continue;
                q.push(neighbor);
            }
        }
        return -1; //dummy.

    }
    void buildGraph(TreeNode* root, TreeNode* parent, int k) {
        if(root==NULL)
            return;
        if(root->val == k)
            start = root;
        if(parent) {
            graph[parent].push_back(root);
            graph[root].push_back(parent);
        }
        buildGraph(root->left, root, k);
        buildGraph(root->right, root, k);        
    }
};