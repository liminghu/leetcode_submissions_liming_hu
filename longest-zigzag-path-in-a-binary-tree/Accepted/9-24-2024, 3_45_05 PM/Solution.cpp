// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

/*
You are given the root of a binary tree.
A ZigZag path for a binary tree is defined as follow:
Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
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
//int pathLength = 0;
    int longestZigZag(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    /*    int l = 0;
        int r = 0;
        int ans = 0;
        dfs(root, l, r, ans);
        return ans;*/
   /*     dfs(root, false, 0);
        dfs(root, true, 0);
        return pathLength;
    }
    void dfs(TreeNode* node, bool goLeft, int steps) {
        if(node == NULL)
            return;
        pathLength = max(pathLength, steps);
        if(goLeft) { // go left
            dfs(node->left, false, steps+1); //go left, then right.
            dfs(node->right, true, 1); // if we decide to go right, then next step must go left, and ignore parent steps.
        } else { //go right.
            dfs(node->right, true, steps+1); //go right, then left.
            dfs(node->left, false, 1); // if we decide to go left, then next step must go right, and ignore parent steps.          
        }*/
    }

    pair<int,int> helper(TreeNode* curr, int& res) {
        if(curr == NULL)
            return {-1, -1};
        pair<int, int> left = helper(curr->left, res);
        pair<int, int> right = helper(curr->right, res);
        pair<int, int> curr_result = make_pair(left.second+1, right.first+1);
        res = max(res, max(curr_result.first, curr_result.second));
        return curr_result;
    }

/*
Parameters:
l = count of max zigzag which reaches current Node by moving LEFT from par Node.
r = count of max zigzag which reaches current Node by moving RIGHT from par Node.
Now update ans upto current node
then send l+1 to RIGHT
and r+1 to LEFT
*/
 /*   void dfs(TreeNode* root, int l, int r, int& ans) {
        if(!root)
            return;
        ans = max(ans, l);
        ans = max(ans, r);
        dfs(root->left, 0, l+1, ans);
        dfs(root->right, r+1, 0, ans);
        return;
    }*/
};