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
/*Let's try and rephrase the problem a bit to see what it means in terms of the given graph. 
We are given an undirected graph and are asked to find the number of bridges in the graph. 
A bridge is essentially an edge whose removal would make the graph disconnected.
*/
int MOD = 100001;
using LL = long long;
class Solution {
private:
    unordered_map<int, vector<int>> graph_; //adjacency list
    unordered_map<int, int> rank_;
    unordered_set<LL> connDict_;

    int dfs(int node, int discoveryRank) {
        // That means this node is already visited. We simply return the rank.
        if ( rank_.find(node) != rank_.end() )
            return rank_[node];
        
        //not visited. Update the rank of this node.
        rank_[node] = discoveryRank;
        
        // This is the max we have seen till now. So we start with this instead of INT_MAX or something.
        int minRank = discoveryRank + 1;
        
        for (auto neighbor : graph_[node]) {       //We iterate over all the neighbors of the node     
            // Skip the parent.
            if(rank_.find(neighbor) != rank_.end() && rank_[neighbor] == discoveryRank - 1)
                continue;           
            // Recurse on the neighbor.
            int recursiveRank = dfs(neighbor, discoveryRank + 1);
            
            // Step 1, check if this edge needs to be discarded.
            if (recursiveRank <= discoveryRank) {
                int sortedU = min(node, neighbor); 
                int sortedV = max(node, neighbor);
                LL key = LL(sortedU) * MOD + sortedV;
                connDict_.erase(key);
            }
            
            // Step 2, update the minRank if needed.
            minRank = min(minRank, recursiveRank);
        }
        
        return minRank;
    } 

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //Tarjan's algorithm
        //An edge is a critical connection, if and only if it is not in a cycle.
        /*
            the problem simply boils down to finding all the cycles in the graph and discarding
            all the edges belonging to such cycles. If we do that, we will only be left with edges
            that are critical connections in the graph.
        */
        for(auto edge : connections) {  //vector<int>          
            // Bidirectional edges
            int u = edge[0];
            int v = edge[1];
            graph_[u].push_back(v); //unordered_map<int, vector<int>> graph
            graph_[v].push_back(u);
            
            int sortedU = min(u, v);
            int sortedV = max(u, v);
            LL key = (LL) sortedU * MOD + sortedV;
            connDict_.insert( key ); //unordered_set<pair<int, int>> connDict
        }
        dfs(0, 0); //int node: 0, int discoveryRank: 0
        
        vector<vector<int>> result;
        for (LL  criticalConnection : connDict_) {
            int u = criticalConnection / (MOD);
            int v = criticalConnection % (MOD);
            result.push_back({u,v});
        }
        
        return result;
    } 
};            
