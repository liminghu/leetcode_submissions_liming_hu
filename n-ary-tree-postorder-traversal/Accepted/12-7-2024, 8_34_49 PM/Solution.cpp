// https://leetcode.com/problems/n-ary-tree-postorder-traversal

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
    vector<int> postorder(Node* root) {
        vector<int> rets;
        if(root==NULL)
            return {};
        for(int i=0; i<(root->children).size(); i++) {
            vector<int> child_i = postorder(root->children[i]);
            rets.insert(rets.end(), child_i.begin(), child_i.end());
        }
        rets.push_back(root->val);
        return rets;
    }
};