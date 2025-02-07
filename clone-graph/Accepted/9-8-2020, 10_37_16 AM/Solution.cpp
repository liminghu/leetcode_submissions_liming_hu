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
		
		Node* copy = new Node(node -> val, {});
		mc[node] = copy;
		
		//BFS. 
        queue<Node*> todo; //to do.
        todo.push(node);
        
        while(!todo.empty()) {
            Node* s = todo.front(); 
            todo.pop();
            
            for(Node* ss : s->neighbors) {
                if(mc.find(ss) == mc.end() ) {
                    mc[ss] = new Node( ss->val, {} );
					todo.push(ss);
				}
                mc[s]->neighbors.push_back( mc[ss] );
            }                      
        }
        return mc[node];      
    }
private:
	unordered_map<Node*, Node*> mc;
};