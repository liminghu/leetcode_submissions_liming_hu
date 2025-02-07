// https://leetcode.com/problems/binary-tree-right-side-view

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
 
    vector<int> rightSideView(TreeNode* root) {  //bfs
        if (root == NULL) return vector<int>();

        queue<TreeNode*> queue;
        queue.push(root);
        queue.push(NULL);
        TreeNode *prev, *curr = root;
        vector<int> rightside;

        while (!queue.empty()) {
            prev = curr;
            curr = queue.front();
            queue.pop();

            while (curr != NULL) {
                // add child nodes in the queue
                if (curr->left != NULL) {
                    queue.push(curr->left);
                }
                if (curr->right != NULL) {
                    queue.push(curr->right);
                }

                prev = curr;
                curr = queue.front();
                queue.pop();
            }

            // the current level is finished
            // and prev is its rightmost element
            rightside.push_back(prev->val);

            // add a sentinel to mark the end
            // of the next level
            if (!queue.empty()) queue.push(NULL);
        }
        return rightside;




    /*    vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
        q.push(root);
        q.push(NULL);
        TreeNode* cur;
        int layer = 0;
        unordered_map<int,bool> layer_visited;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(cur==NULL ) {
                layer++;
            } else if(cur!=NULL) {
                if(layer_visited.find(layer)==layer_visited.end()) {
                    ans.push_back(cur->val);
                    layer_visited[layer] = true;
                }
                if(cur->right == NULL  && cur->left!=NULL) {
                    q.push(cur->left);
                    q.push(NULL);
                    
                }
                else if(cur->right != NULL && cur->left!=NULL)  {
                    q.push(cur->right);
                    q.push(cur->left);
                    q.push(NULL);
                    
                } else if(cur->right != NULL && cur->left==NULL) {
                    q.push(cur->right);
                    q.push(NULL);
                   
                }
            };
        };
        
        return ans;
        */
    }
};