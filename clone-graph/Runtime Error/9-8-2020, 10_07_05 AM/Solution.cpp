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
		
		//BFS. 
		unordered_map<Node*, Node*> mc;
		unordered_set<Node*> done;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            Node* s = q.front(); 
            q.pop();
            if(done.count(s)) continue;  //we have seen t before.
            done.insert(s);
            
            if(mc.find(s) != mc.end() ) {
                mc[s] = new Node(s->val);                
            }
            Node* t = mc[s];
            for(Node* ss : s->neighbors) {
                if(mc.find(ss) != mc.end() ) 
                    mc[ss] = new Node( ss->val );
                q.push(ss);
                t->neighbors.push_back( mc[ss] );
            }                      
        }
        return mc[node];      
    }
};