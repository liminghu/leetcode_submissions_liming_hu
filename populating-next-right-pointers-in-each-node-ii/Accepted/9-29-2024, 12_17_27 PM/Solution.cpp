// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
Given a binary tree
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Constraints:
The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                Node* f = q.front();
                q.pop();
                if(i<size-1)
                    f->next = q.front();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            };
        }
        return root;
    }
};