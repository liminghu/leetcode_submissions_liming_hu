// https://leetcode.com/problems/critical-connections-in-a-network

/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections 
forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. 
Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach 
some other server.
Return all critical connections in the network in any order.
2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/
class Solution {
    vector<vector<int>>rets;
    vector<vector<int>>next;
    int time = 0;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        next.resize(n);
        for (auto x:connections) {
            next[x[0]].push_back(x[1]);
            next[x[1]].push_back(x[0]);
        }
            
        vector<bool>visited(n);
        vector<int>dfn(n,0);
        vector<int>low(n,0);
        vector<int>parent(n,-1);
        
        for (int i = 0; i < n; i++)  {            
            if (visited[i] == false) 
                DFS(i, visited, dfn, low, parent); 
        }
        
        return rets;
    }
    
    
    void DFS(int u, vector<bool>&visited, vector<int>&dfn, vector<int>&low, vector<int>&parent) {  
        visited[u] = true; 
        time++;
        dfn[u] = low[u] = time; 
              
        for (int v : next[u]) { 
            if (v == parent[u])
                continue;
            
            if (!visited[v]) { 
                parent[v] = u; 
                DFS(v, visited, dfn, low, parent); 
                if (low[v] > dfn[u]) rets.push_back({v,u}); // critical edge               
                // if(low[v] >= dfn[u]), then u is a critical vertex               
                low[u]  = min(low[u], low[v]); 
            } else             
                low[u]  = min(low[u], dfn[v]); 
        } 
    } 
};