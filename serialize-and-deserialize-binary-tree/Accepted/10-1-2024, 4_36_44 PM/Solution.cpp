// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //inorder, postorder
        string str = "";
        if(root == NULL)
            str += "null\n";
        else {
            str += to_string(root->val)+ "\n";
            str += serialize(root->left);
            str += serialize(root->right); 
        };
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if(val == "null")
            return NULL;
        TreeNode* root = new TreeNode( stoi(val) );
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));