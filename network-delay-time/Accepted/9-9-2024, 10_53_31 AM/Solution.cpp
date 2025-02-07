// https://leetcode.com/problems/network-delay-time

/*You are given a network of n nodes, labeled from 1 to n. You are also given times, 
a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the 
source node, vi is the target node, and wi is the time it takes for a signal to 
travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for 
all the n nodes to receive the signal. If it is impossible for all the n nodes 
to receive the signal, return -1.
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //times[i] = (ui, vi, wi)
        vector<vector<int>> adj[n+1];
        for(auto& time: times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            adj[ source ].push_back( {travelTime, dest}); //travletime, dest.
        };       
        vector<int> signalReceivedAt(n+1, INT_MAX);
        queue<int> q;
        q.push(k);
        signalReceivedAt[k] = 0;
        while(!q.empty()) {
            int curNodeNum = q.front();
            q.pop();
            for(vector<int> edge: adj[curNodeNum]) {
                int time = edge[0];
                int neighborNode = edge[1];
                int arrivalTime = signalReceivedAt[curNodeNum] + time;
                if(signalReceivedAt[neighborNode] > arrivalTime ) {
                    signalReceivedAt[neighborNode] = arrivalTime;
                    q.push(neighborNode);
                }
            }
        }        

        int ret = INT_MIN;
        for(int i=1; i<=n; i++) 
            ret = max(ret, signalReceivedAt[i]);
        return ret == INT_MAX? -1: ret;
        
/*        vector<vector<int>> adj[n+1];
        for(auto& time: times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            adj[ source ].push_back( {travelTime, dest}); //travletime, dest.
        };
        
        vector<int> signalReceivedAt(n+1, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //minimum
        pq.push({0, k}); //timeRecived, source.
        signalReceivedAt[k] = 0;
        while(!pq.empty()) {
            vector<int> curNode = pq.top();
            int curNodeTime = curNode[0];
            int curNodeNum = curNode[1];
            pq.pop();

            if(curNodeTime > signalReceivedAt[curNodeNum] ) //This node will not help.
                continue;
            for(vector<int> edge: adj[curNodeNum]) {
                int time = edge[0];
                int neighborNode = edge[1];
                if(signalReceivedAt[neighborNode] > curNodeTime + time ) {
                    signalReceivedAt[neighborNode] = curNodeTime + time;
                    pq.push({curNodeTime + time, neighborNode});
                }
            }
        }

        int ret = INT_MIN;
        for(int i=1; i<=n; i++) 
            ret = max(ret, signalReceivedAt[i]);
        return ret == INT_MAX? -1: ret;*/
    }
};