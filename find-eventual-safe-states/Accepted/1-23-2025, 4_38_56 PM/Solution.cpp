// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {//graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
        int n = graph.size();
        vector<int> outDegree(n, 0);
        //Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
        // A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
        set<int> safe;
        vector<vector<int>> parent(n);       
        for(int i=0; i<n; i++) {
            //graph[i][j]
            outDegree[i] = graph[i].size();
            if (outDegree[i]==0)
                safe.insert(i);
            for(int j=0; j<graph[i].size(); j++) {
                int dest_node = graph[i][j];
                parent[dest_node].push_back(i);
            };    
        };
        queue<int> q;
        for(auto& item: safe) {
            q.push(item);
        }
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                int cur = q.front();
                q.pop();
                for(int j=0; j<parent[cur].size(); j++) {
                    outDegree[ parent[cur][j] ] --;
                    if(outDegree[ parent[cur][j] ] == 0) {
                        q.push(parent[cur][j]);
                        safe.insert(parent[cur][j]);
                    };
                }
            }
        };
        vector<int> ans(safe.begin(), safe.end());
        return ans;
    }
};