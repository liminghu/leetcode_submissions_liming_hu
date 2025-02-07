// https://leetcode.com/problems/delete-nodes-and-return-forest

/*Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest. You may return the result in any order.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        /* The number of nodes in the given tree is at most 1000.
            Each node has a distinct value between 1 and 1000.
            to_delete.length <= 1000
            to_delete contains distinct values between 1 and 1000.
        */
        vector<TreeNode*> forest;
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        root = delNodes_helper(root, toDeleteSet, forest);
        if(root) 
            forest.push_back(root);

        return forest;

    }


    TreeNode* delNodes_helper(TreeNode* &root, unordered_set<int> toDeleteSet, vector<TreeNode*>& forest) {
        
        if(root == nullptr) 
            return nullptr;
        
        root->left = delNodes_helper(root->left, toDeleteSet, forest); 
        root->right = delNodes_helper(root->right, toDeleteSet, forest);

        if(toDeleteSet.find(root->val) !=toDeleteSet.end()) {
            if(root->left)
                forest.push_back(root->left);
            if(root->right)
                forest.push_back(root->right);    
            delete root;
            return nullptr;
        }

        return root;
        
    }
};