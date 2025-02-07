// https://leetcode.com/problems/cheapest-flights-within-k-stops

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that 
there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such 
route, return -1.
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); 
        for(int i=0; i<flights.size(); i++) {
            int from_i = flights[i][0];
            int to_i = flights[i][1];
            int price_i = flights[i][2];
            adj[ from_i ].push_back({to_i,price_i});
        };
        vector<int> stops(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //min
        //dist_from_src_node, node, number_of_stops_from_src_node
        pq.push({0, src, 0});
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int dist = t[0];
            int node = t[1];
            int steps = t[2];
            if(steps > stops[node] || steps > k+1)
                continue;
            stops[node] = steps;
            if(node == dst)
                return dist;
            for(auto [neighbor, price]: adj[node]) {
                pq.push({dist+price, neighbor, steps+1});
            }
        }
        return -1;

    }
};