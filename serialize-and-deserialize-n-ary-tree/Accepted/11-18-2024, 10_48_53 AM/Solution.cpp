// https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree

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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        serial_helper(root, s);
        return s;
    }
    void serial_helper(Node* root, string& s) {
        if(!root)
            return;
        s += " " + to_string(root->val) +  " " + to_string(root->children.size());
        for(auto p: root->children) 
            serial_helper(p, s);
    };
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        queue<string> q;
        string s;
        for(int i=1; i<data.size(); i++) {
            if(data[i] == ' ') {
                q.push(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        if(s.size() != 0 )
            q.push(s);
        return deserial_helper(q);
    }
    Node* deserial_helper(queue<string>&q) {
        Node* root = new Node( stoi( q.front() ) );
        q.pop();
        int size = stoi(q.front());
        q.pop();
        for(int i=0; i<size; i++) {
            root-> children.push_back(deserial_helper(q));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));