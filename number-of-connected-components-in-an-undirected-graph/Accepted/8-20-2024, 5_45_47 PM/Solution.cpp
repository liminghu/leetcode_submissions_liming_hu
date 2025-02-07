// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

/*
You have a graph of n nodes. You are given an integer n and an array edges where 
edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.
Return the number of connected components in the graph.
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        /*  1 <= n <= 2000
            1 <= edges.length <= 5000
            edges[i].length == 2
            0 <= ai <= bi < n
            ai != bi
            There are no repeated edges.
        */
        
        vector<bool> visited(n, false);
        vector<int> adjList[n];
        int res = 0;
        for(int i=0; i<edges.size(); i++) {
            adjList[ edges[i][0] ].push_back( edges[i][1] );
            adjList[ edges[i][1] ].push_back( edges[i][0] );
        }

        for(int i=0; i<n; i++) {
            if(visited[i] == true) 
                continue;
            res++;
            dfs(adjList, visited, i);
        }
        return res;       
    }
    void dfs(vector<int> adjList[], vector<bool>& visited, int start) {
        visited[start] = true;
        for(int i=0; i<adjList[start].size(); i++) {
            if(visited[ adjList[start][i] ] == false)
                dfs(adjList, visited, adjList[start][i]);
        }
    }
};