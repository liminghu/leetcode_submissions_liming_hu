// https://leetcode.com/problems/distribute-coins-in-binary-tree

/*
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. 
There are n coins in total throughout the whole tree.
In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may 
be from parent to child, or from child to parent.
Return the minimum number of moves required to make every node have exactly one coin.
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
    int distributeCoins(TreeNode* root) {
        /*  The number of nodes in the tree is n.
            1 <= n <= 100
            0 <= Node.val <= n
            The sum of all Node.val is n.
        */
        if(root == NULL)
            return 0;
        int res = 0;
        int leftNode = 0;
        int leftCoins = numCoins(root->left, leftNode);
        //cout << "leftCoins = " << leftCoins << " leftNode = " << leftNode << endl;
        int numLeftDistributions = abs(leftNode - leftCoins);
        int totalLeft = numLeftDistributions;
        if(root->left != NULL) {
            if(root->left->val > 1) 
                root->left->val -= abs(leftCoins -leftNode);
            else
                root->left->val += abs(leftCoins -leftNode);
            totalLeft += distributeCoins(root->left);
            root->val = 1;
        };
        res += totalLeft;

        int rightNode = 0;
        int rightCoins = numCoins(root->right, rightNode);
        //cout << "rightCoins = " << rightCoins << " rightNode = " << rightNode << endl;
        int numRightDistributions = abs(rightNode - rightCoins);
        int totalright = numRightDistributions;
        if(root->right != NULL) {
            if(root->right->val > 1)
                root->right->val -= abs(rightCoins -rightNode);
            else
                root->right->val += abs(rightCoins -rightNode);
            totalright += distributeCoins(root->right);
            root->val = 1;
        };
        res += totalright;

        return res;
    }

    int numCoins(TreeNode* root, int& numNode) {
        if(root==NULL) {
            numNode = 0;
            return 0;
        }
        int leftNode = 0;
        int leftCoins = numCoins(root->left, leftNode);
        int rightNode = 0;
        int rightCoins =  numCoins(root->right, rightNode);
        numNode = 1 + leftNode + rightNode;
        return root->val + leftCoins + rightCoins;
    }
};