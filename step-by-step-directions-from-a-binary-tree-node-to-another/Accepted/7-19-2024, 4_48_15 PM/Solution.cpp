// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

/*You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.*/

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        /* The number of nodes in the tree is n.
            2 <= n <= 105
            1 <= Node.val <= n
            All the values in the tree are unique.
            1 <= startValue, destValue <= n
            startValue != destValue
        */

        //path from root to start.     first we need to remove the common nodes.      finally reverse.
        string root_start;
        rootDirections(root, startValue, root_start);
        reverse(root_start.begin(), root_start.end());
        //cout << "root_start = "<< root_start << endl;

        //path from root to end
        string root_dest;
        rootDirections(root, destValue, root_dest);
        reverse(root_dest.begin(), root_dest.end());
        //cout << "root_dest = "<< root_dest << endl;

        int i=0;
        while(i< root_start.length() && i < root_dest.length() ) {
            if(root_start[i] == root_dest[i]) {
                i++;
            } else 
                break;
        }

        root_start.erase(0, i);
        //cout << "root_start = "<< root_start << endl;
        root_dest.erase(0, i);
        //cout << "root_dest = "<< root_dest << endl;

        //reverse root_start
        for(int i=0; i<root_start.length(); i++) {
            root_start[i] = 'U';
        }

        return root_start + root_dest;
    }

    bool rootDirections(TreeNode* root, int value, string &path) {
        
        if(root == nullptr) //this should never happen.
            return false;
        
        if(root->val == value)
            return true;
        if( root->left && rootDirections(root->left, value, path) )
            path.push_back('L');
        else if ( root->right && rootDirections(root->right, value, path) )
            path.push_back('R');

        return !path.empty(); 
    }
};