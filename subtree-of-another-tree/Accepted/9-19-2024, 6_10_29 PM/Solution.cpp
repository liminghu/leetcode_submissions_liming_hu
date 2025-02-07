// https://leetcode.com/problems/subtree-of-another-tree

/*Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the 
same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
The tree tree could also be considered as a subtree of itself.
The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
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
    bool isSametree(TreeNode* s, TreeNode* t) {
        if(!s || !t) { ////if any of the tree is null then there is no need to compare 
            return s == NULL && t == NULL;
        };

        if(s->val == t->val) { //since both are not null check if they have same value otherwise return false
            return isSametree(s->left, t->left) && isSametree(s->right, t->right);
        } else
            return false;       
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return subRoot == NULL;
        if(isSametree(root, subRoot))
            return true;
        else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
};