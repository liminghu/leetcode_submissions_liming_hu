// https://leetcode.com/problems/inorder-successor-in-bst-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) { //All Nodes will have unique values.
        //Given a node in a binary search tree, return the in-order successor of that node in the BST. If that node has no in-order successor, return null
        if(node==NULL)
            return NULL;
        if(node->right == NULL) {
            if (node->parent->left == node)
                return node->parent;
            else
                return NULL;
        }
        return smallestChild(node->right);
    }
    Node* smallestChild(Node* node) {
        if(node==NULL)
            return NULL;
        if(node->left)
            return smallestChild(node->left);
        else
            return node;
    }
};