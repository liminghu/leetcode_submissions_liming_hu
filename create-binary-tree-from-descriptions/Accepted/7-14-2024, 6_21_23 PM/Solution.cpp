// https://leetcode.com/problems/create-binary-tree-from-descriptions

/*You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates 
that parenti is the parent of childi in a binary tree of unique values. Furthermore,
If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.
The test cases will be generated such that the binary tree is valid.
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        /*  1 <= descriptions.length <= 104
            descriptions[i].length == 3
            1 <= parenti, childi <= 105
            0 <= isLefti <= 1
        */
        TreeNode* root;
        int sz = descriptions.size();
        unordered_map<int, vector<pair<int, int>>> children;
        unordered_set<int> root_set;
        for(int i=0; i<sz; i++) {
            children[descriptions[i][0]].push_back({descriptions[i][1], descriptions[i][2]} ); //[parenti, childi, isLefti]
            root_set.insert(descriptions[i][1]); //insert node which has parent.
        };
        int root_val = -1;
        for(auto child: children) {
            if(root_set.find(child.first)== root_set.end()) {
                root_val = child.first;
                break;
            }
        }

        root = new TreeNode(root_val);
        //build_tree(root, children);
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
            TreeNode* cur_node = qu.front();
            qu.pop();

            int root_val = cur_node->val;
            vector<pair<int, int>> child_root = children[root_val];
            for(int i=0; i<child_root.size(); i++) {
                if(child_root[i].second)  {//isleft
                    TreeNode* left = new TreeNode(child_root[i].first);
                    cur_node->left = left;
                    qu.push(left);
                } else {
                    TreeNode* right = new TreeNode(child_root[i].first);
                    cur_node->right = right;
                    qu.push(right);
                }
            }
        }

        return root;

    }

    /*void build_tree(TreeNode* root, unordered_map<int, vector<pair<int, int>>> children) {
        int root_val = root->val;
        vector<pair<int, int>> child_root = children[root_val];
        for(int i=0; i<child_root.size(); i++) {
            if(child_root[i].second)  {//isleft
                TreeNode* left = new TreeNode(child_root[i].first);
                root->left = left;
                build_tree(root->left, children);
            } else {
                TreeNode* right = new TreeNode(child_root[i].first);
                root->right = right;
                build_tree(root->right, children);
            }
        }
    };*/
};