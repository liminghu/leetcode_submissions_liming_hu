// https://leetcode.com/problems/graph-valid-tree

/*
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between nodes ai and bi in the graph.
Return true if the edges of the given graph make up a valid tree, and false otherwise.
 */
class Solution {
private:
    unordered_set<int> visited;
    vector<vector<int>> adjancyMatrix;

public:
    bool validTree(int n, vector<vector<int>>& edges) {
                                                /*1 <= n <= 2000
                                                0 <= edges.length <= 5000
                                                edges[i].length == 2
                                                0 <= ai, bi < n
                                                ai != bi
                                                There are no self-loops or repeated edges.
                                                */
        //check whether we can traverse from one node to all the rest nodes.
        //no loop.
        if(edges.size() != n-1)
            return false;        
        adjancyMatrix = vector(n, vector<int>());

        for(int i=0; i<edges.size(); i++) {
            adjancyMatrix[edges[i][0]].push_back(edges[i][1]);
            adjancyMatrix[edges[i][1]].push_back(edges[i][0]);
        };

        return dfs(0, -1) && visited.size() == n;                                             
    }

    bool dfs(int node, int parent) {
        if(visited.contains(node))
            return false;
        visited.insert(node);
        for(int neighbor: adjancyMatrix[node]) {
            if(parent != neighbor) {
                bool result = dfs(neighbor, node);
                if(!result)
                    return false;
            }
        }
        return true;
    }
};