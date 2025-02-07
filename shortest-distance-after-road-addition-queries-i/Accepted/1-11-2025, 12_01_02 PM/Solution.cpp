// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        //queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. 
        //After each query, you need to find the length of the shortest path from city 0 to city n - 1
        //answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> dist(n);
        for(int i=0; i<n; i++)
            dist[i] = i;
        for(int i=0; i<n-1; i++)
            adj[i].push_back(i+1);
        for(auto query:queries) {
            int a = query[0], b = query[1];
            adj[a].push_back(b);
            if(dist[a]+1<dist[b]) {
                queue<int> q;
                q.push(b);
                dist[b] = dist[a]+1;
                while(!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for(auto nxt: adj[cur]) {
                        if(dist[cur]+1<dist[nxt]) {
                            dist[nxt] = dist[cur]+1;
                            q.push(nxt);
                        }
                    }
                }
            }
            ans.push_back(dist.back());
        }
        return ans;
    }
};