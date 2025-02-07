// https://leetcode.com/problems/construct-binary-tree-from-string

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
    TreeNode* str2tree(string s) {//preorder
        if(s.empty())
            return NULL;
        istringstream in(s);
        TreeNode* node = str2tree(in);
        return node;
    }
    TreeNode* str2tree(istringstream& in) {
        int num;
        TreeNode* node;
        if(in>>num) {
            node = new TreeNode(num);
        }
        char c;
        while(in >> c) {
            if( c=='(' && !(node->left) ) 
                node->left = str2tree(in);
            else if( c=='(' && node->left)
                node->right = str2tree(in);
            else if(c==')')
                break;
        }
        return node;
    }
};