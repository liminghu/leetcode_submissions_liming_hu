// https://leetcode.com/problems/kth-ancestor-of-a-tree-node

/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array 
parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the 
kth ancestor of a given node.
The kth ancestor of a tree node is the kth node in the path from that node to the root node.
Implement the TreeAncestor class:
TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the 
tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there
 is no such ancestor, return -1.
1 <= k <= n <= 5 * 104
parent.length == n
parent[0] == -1
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5 * 104 queries.
*/
class TreeAncestor {
    vector<vector<int>> ancester_;
public:
    TreeAncestor(int n, vector<int>& parent) { //parent[i] is the parent of ith node
       //parent[0] == -1 
       vector<vector<int>> ancester(n, vector<int>(31, -1)); //ancester[i][j] the 2^j th ancester of node i. maximum: 31th.
       for(int i=0; i<n; i++)
            ancester[i][0] = parent[i];
        for(int j=1; j<31; j++) {
             for(int i=0; i<n; i++) {
                int j_1th_anc = ancester[i][j-1];
                if( j_1th_anc != -1 )
                    ancester[i][j] = ancester[ j_1th_anc ][ j - 1 ];
             }
        } 
        this->ancester_ = ancester;
    }
    
    int getKthAncestor(int node, int k) { //Find the kth ancestor of a given node.
        for(int j=0; j<31; j++) {
            if( (k>>j) & 1 ) {
                node = ancester_[node][j];
                if(node == -1 )
                    break;
            };
        };
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */