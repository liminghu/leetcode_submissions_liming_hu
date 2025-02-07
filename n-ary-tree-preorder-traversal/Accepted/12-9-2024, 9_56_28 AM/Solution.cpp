// https://leetcode.com/problems/n-ary-tree-preorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> rets;
        if(root==NULL)
            return {};
        rets.push_back(root->val);
        for(int i=0; i<root->children.size(); i++) {
            vector<int> child_i = preorder(root->children[i]);
            rets.insert(rets.end(), child_i.begin(), child_i.end());
        };
        return rets;
    }
};