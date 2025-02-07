// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
		if(node == nullptr) return nullptr;
		
		//DFS. 
		if(mc.find(node) == mc.end()) { 			
			Node* copy = new Node(node->val, {});
			mc[node] = copy;
			for ( Node* neighbor: node->neighbors) {
				copy->neighbors.push_back(cloneGraph(neighbor));
		    }
        }
        return mc[node];
    }
private:
	unordered_map<Node*, Node*> mc;
};