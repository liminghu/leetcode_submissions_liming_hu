// https://leetcode.com/problems/binary-search-tree-iterator

/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the 
constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
Constraints:
The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.
Follow up:
Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree? 
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
class BSTIterator {
private:
    vector<int> nodeSorted;
    int idx;
    void inorder(TreeNode* root) {
        if(root==NULL)
            return;
        this->inorder(root->left);
        this->nodeSorted.push_back(root->val);
        this->inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        //The pointer should be initialized to a non-existent number smaller than any element in the BST.
        idx = -1;
        this->nodeSorted = vector<int>();
        inorder(root);
    }
    
    int next() {
        return this->nodeSorted[++idx];
    }
    
    bool hasNext() {
        return this->idx+1 < this->nodeSorted.size();
    }
};

/*class BSTIterator {
private:
    stack<TreeNode*> st_;
    void pushAllLeft(TreeNode* node) {
        for(; node != NULL; node = node->left)
            st_.push(node);
    }
public:
    BSTIterator(TreeNode* root) {
        //The pointer should be initialized to a non-existent number smaller than any element in the BST.
        pushAllLeft(root);
        
    }
    
    int next() {
        if(hasNext()) {
            TreeNode* t = st_.top();
            st_.pop();
            pushAllLeft( t->right );
            return t->val;
        }
        return INT_MIN;
    }
    
    bool hasNext() {
        return !st_.empty();
    }
};*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */