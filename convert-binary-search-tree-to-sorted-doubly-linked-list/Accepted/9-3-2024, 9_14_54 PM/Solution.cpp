// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list

/*Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.
You can think of the left and right pointers as synonymous to the predecessor and
 successor pointers in a doubly-linked list. For a circular doubly linked list, 
 the predecessor of the first element is the last element, and the successor of the
  last element is the first element.
We want to do the transformation in place. After the transformation, the left pointer
 of the tree node should point to its predecessor, and the right pointer should point
  to its successor. You should return the pointer to the smallest element of the linked list.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        /*  The number of nodes in the tree is in the range [0, 2000].
            -1000 <= Node.val <= 1000
            All the values of the tree are unique.
        */
        if(root == NULL)
            return NULL;
        if(root->left == NULL && root->right == NULL) {
            Node* rootNode = new Node(root->val);
            rootNode->left = rootNode;
            rootNode->right = rootNode;
            return rootNode;
        }
        
        if( root->left == NULL && root->right != NULL) {            
            Node* rightList = treeToDoublyList(root->right);
            Node* rightend = rightList->left;
            Node* rootNode = new Node(root->val);
            rootNode->left = rightend;
            rootNode->right = rightList;
            rightend->right = rootNode; 
            rightList->left = rootNode;
            //cout << "root val = " << rootNode->val << endl;
            //cout << "root left val = " << rootNode->left->val << endl;
            //cout << "root right val = " << rootNode->right->val << endl;

            return rootNode;
        };

        if( root->left != NULL && root->right == NULL) {            
            Node* leftList = treeToDoublyList(root->left);
            Node* rootNode = new Node(root->val);
            Node* leftend = leftList->left;
            rootNode->left = leftend;
            rootNode->right = leftList;
            leftend->right = rootNode; 
            leftList->left = rootNode;
            //cout << "root val = " << leftList->val << endl;
            //cout << "root left val = " << leftList->left->val << endl;
            //cout << "root right val = " << leftList->right->val << endl;
            return leftList;
        };

        if( root->left != NULL && root->right != NULL) {
            Node* rightList = treeToDoublyList(root->right);
            Node* rootNode = new Node(root->val);
            rootNode->right = rightList;
            Node* rightend = rightList->left;

            Node* leftList = treeToDoublyList(root->left);
            Node* leftend = leftList->left;

            leftList->left = rightend;
            leftend->right = rootNode; 
            
            rightList->left = rootNode;

            rootNode->left = leftend;
            rightend->right = leftList;
            //cout << "root val = " << leftList->val << endl;
            //cout << "root left val = " << leftList->left->val << endl;
            //cout << "root right val = " << leftList->right->val << endl;
            return leftList;
        }

        return NULL;
    }
};