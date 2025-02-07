// https://leetcode.com/problems/second-minimum-time-to-reach-destination

/*
A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge 
between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The 
time taken to traverse any edge is time minutes.

Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals 
change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot 
wait at a vertex if the signal is green.

The second minimum value is defined as the smallest value strictly larger than the minimum value.

For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

Notes:

You can go through any vertex any number of times, including 1 and n.
You can assume that when the journey starts, all signals have just turned green.
*/
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> next[n+1];
        for( auto edge:edges) {
            int a = edge[0]; 
            int b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        vector<int> visited(n+1, 0);
        vector<int> dist(n+1, -1);
        queue<pair<int,int>> q; // <int, arrive time>
        q.push({1,0});
        dist[1] = 0;
        
        while(!q.empty()) {
            auto [cur, t] = q.front();
            q.pop();

            int tt;
            int round = t /change;
            if(round % 2 == 0) //green;
                tt = t+time;  //The time taken to traverse any edge is time minutes.
            else 
                tt = (round+1)*change + time;
            
            for(int nxt: next[cur]) {
                if( visited[nxt] < 2 && dist[nxt] < tt ) {
                    dist[nxt] = tt;
                    visited[nxt]++;
                    q.push({nxt, tt});

                    if(nxt==n && visited[nxt]==2)
                        return tt;
                }
            }
        }

        return -1;
    }
};