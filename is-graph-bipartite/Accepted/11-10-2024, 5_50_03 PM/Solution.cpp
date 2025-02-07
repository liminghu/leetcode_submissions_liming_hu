// https://leetcode.com/problems/is-graph-bipartite

/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] 
is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. 
The graph has the following properties:
There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in 
set A and a node in set B.
Return true if and only if it is bipartite.

 Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

Example 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 
Constraints:
graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.
*/
class Solution {
    unordered_map<int,int> Father;
public:
    bool isBipartite1(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1); //-1:not visited, 0: grp A, 1: grp B.
        for(int i=0; i<n; i++) {
            if(visited[i] != -1) //visited before.
                continue;
            queue<pair<int, int>> q; // {node, grp};
            q.push({i, 0}); //node i, grp 0: A
            while(!q.empty()) {
                pair<int, int> f = q.front();
                int node = f.first;
                int grp = f.second;
                q.pop();
                for(auto& next: graph[node]) {
                    if(visited[next] != -1) { //visited before
                        if(visited[next] == grp) //next in the same grp.
                            return false;
                    } else {
                        visited[next] = 1-grp;
                        q.push({next, 1-grp});
                    }
                }
            }
        }
        return true;
    }
       bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            for(int i=0; i<n; i++) {
                Father[i] = i;
            }
            for(int i=0; i<n; i++) {
                int k;
                if(graph[i].size() > 0)
                    k = graph[i][0];
                for(auto j:graph[i]) {
                    if(FindSet(i) == FindSet(j) )
                        return false;
                    Union(k, j);
                }
            }
            return true;
       }
       int FindSet(int x) {
        if(x!=Father[x])
            Father[x] = FindSet(Father[x]);
        return Father[x];
       };
       void Union(int x, int y) {
            x = Father[x];
            y = Father[y];
            if(x<y)
                Father[y] = x;
            else
                Father[x] = y;
       }
};