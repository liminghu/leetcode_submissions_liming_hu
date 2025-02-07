// https://leetcode.com/problems/redundant-connection-ii

/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which 
all other nodes are descendants of this node, plus every node has exactly one parent, except for the root 
node which has no parents.
The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), 
with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not 
an edge that already existed.
The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a 
directed edge connecting nodes ui and vi, where ui is a parent of child vi.
Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple 
answers, return the answer that occurs last in the given 2D-array.
*/
class Solution {
private:
    unordered_map<int, int> father;
    int findFather(int x) {
        if(father[x]!=x) 
            father[x] = findFather(father[x]);
        return father[x];
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        /*  n == edges.length
            3 <= n <= 1000
            edges[i].length == 2
            1 <= ui, vi <= n
            ui != vi
        */
        vector<int> candidate1;
        vector<int> candidate2;
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if(father.find(v) !=father.end()) {
                candidate1 = {u,v};
                candidate2 = {father[v], v};  //first.
                break;
            } else 
                father[v] = u;
        }
        
        int N = edges.size();//for a tree, the num of edges = num of nodes - 1.
        for(int i=1; i<=N; i++)
            father[i] = i;
        for(auto edge: edges) {
            if(edge == candidate1)
                continue;
            int u = edge[0];
            int v = edge[1];
            if(findFather(u) != findFather(v))
                father[v] = u; //union.
            else {  //loop
                if(candidate2.size() == 0) 
                    return edge; //first.
                else
                    return candidate2;
            }
        }
        return candidate1;
    }
};