// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups

class Solution {
    vector<int> adj[501]; //adjacent graph
    int col[501];
    int dist[501][501];
    bool flag = false;
    //nodes in a connected graph
    vector<int> connectedNodes;
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        //edges[i] = [ai, bi]
        /*Divide the nodes of the graph into m groups (1-indexed) such that:
        Each node in the graph belongs to exactly one group.
        For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
        */
        //Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.
        //no cycle of odd nodes.
        for(auto& edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        };
        for(int src=1; src<=n; src++)
            bfs(src); ////calculate minimum distance between all nodes, start from src
        int ans = 0;
        int in = 0;
        for(int i=1; i<=n; i++) {
            if(col[i] == 0) {
               connectedNodes.clear();
               flag = true;
               in++;
               dfs(i);
               if(!flag)
                return -1;
                int mxdist = 0;
                for(int i: connectedNodes) {
                    for(int j:connectedNodes) {
                        mxdist = max(mxdist, dist[i][j]);
                    }
                } 
                ans+= mxdist;
            }
        }
        return ans;

    }
    //calculate minimum distance between all nodes.
    void bfs(int src) {
        for(int i=1; i<=500; i++)
            dist[src][i] = INT_MAX;
        dist[src][src] = 1;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int next:adj[cur]) { //cur->next
                if(dist[src][next]>dist[src][cur]+1) {
                   dist[src][next]=dist[src][cur]+1;
                   q.push(next); 
                } 
            }
        };
    }
    //check if graph is bipartie
    void dfs(int u, int c=1) {
        col[u] = c;
        connectedNodes.push_back(u);
        for(int v: adj[u]) {
            if(!col[v] )
                dfs(v, 3-c);
            else
                if(col[v]==c)
                    flag = 0; //graph is not bipartite.
        }
    }

};