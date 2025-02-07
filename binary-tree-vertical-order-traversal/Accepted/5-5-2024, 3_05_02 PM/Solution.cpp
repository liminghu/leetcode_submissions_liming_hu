// https://leetcode.com/problems/binary-tree-vertical-order-traversal

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        // the column number as the key of the hash and define vector<height, val> as the value of the hash. group all the elements with same column in separate vectors.
        map<int, vector<pair<int, int>> > hash;

        //the preorder traversal to visit all the nodes and while visiting the nodes also keep track of height (row) and column of the nodes.
        preorder_traversal(root, 0, hash, 0); //L: root's column as 0. h: root's height as 0
        
        for(auto e: hash) {
            vector<int> tmp;
            vector<pair<int, int>> sorted = e.second;
            sort(sorted.begin(), sorted.end(), [](pair<int, int> a, pair<int, int> b) { return (a.first < b.first);});
            for(auto f: sorted) {
                tmp.push_back(f.second); //value
            }
            res.push_back(tmp);
        }
        return res;
    }

    void preorder_traversal(TreeNode* root, int col, map<int, vector<pair<int, int>> > &hash, int height) {
        if (!root)
            return;
        hash[col].push_back(make_pair(height, root->val));
        preorder_traversal(root->left, col-1, hash, height+1);
        preorder_traversal(root->right, col+1, hash, height+1);
    }
};