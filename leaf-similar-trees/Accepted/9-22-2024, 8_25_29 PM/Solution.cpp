// https://leetcode.com/problems/leaf-similar-trees

/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
Constraints:
The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1 = leaf(root1);
        vector<int> leaf2 = leaf(root2);
        if(leaf1 == leaf2)
            return true;
        else
            return false;
    }
    vector<int> leaf(TreeNode* root) {
        vector<int> ret;
        if(root== NULL)
            return ret;
        if(root->left == NULL && root->right == NULL) {
            ret.push_back(root->val);
            return ret;
        };
        ret =  leaf(root->left);
        vector<int> right =  leaf(root->right);
        ret.insert( ret.end(), right.begin(), right.end() );
        return ret;
    }
};