// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii

/*Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a 
tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."
*/
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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        /*The number of nodes in the tree is in the range [2, 105].
            -109 <= Node.val <= 109
            All Node.val are unique.
            p != q
            p and q exist in the tree.*/
        
        vector<Node*> path_p;
        Node* cur = p;
        while(cur) {
            path_p.push_back(cur);
            cur = cur->parent;
        };

        vector<Node*> path_q;
        cur = q;
        while(cur) {
            path_q.push_back(cur);
            cur = cur->parent;
        };

        long i=path_p.size()-1;
        long j=path_q.size()-1;
        for(; i>=0; i--, j--) {
            if(path_p[i] != path_q[j])
                break;
        };

        return path_p[i+1];
    }
};